#!/usr/bin/env bash
# Compile every content header standalone against the team template.
# Snippets must be self-contained: paste one into a solution and it works.
set -uo pipefail
cd "$(dirname "$0")/.."

# An inherited CXX that is not actually runnable (make's built-in default, a
# stale path) falls back to the search below rather than failing 31 times.
CXX=${CXX:-}
if [ -n "$CXX" ] && ! command -v "$CXX" >/dev/null 2>&1; then
	echo "test-compiles: CXX=$CXX is not runnable, looking for another compiler" >&2
	CXX=""
fi
if [ -z "$CXX" ]; then
	for c in g++-16 g++-15 g++-14 g++-13 g++; do
		command -v "$c" >/dev/null 2>&1 && { CXX=$c; break; }
	done
fi
[ -n "$CXX" ] || { echo "test-compiles: no C++ compiler found" >&2; exit 1; }

TMP=build/test-compiles
mkdir -p "$TMP"
trap 'rm -rf "$TMP"' EXIT

# Template minus the x86-only perf pragmas (they break on arm64) and minus
# solve()/main(); keeps includes, macros and typedefs.
sed -e '/^#pragma GCC/d' -e '/^void solve/,$d' content/contest/Template.cpp > "$TMP/prelude.h"

STD=-std=c++20
mapfile -t HEADERS < <(find content -name '*.h' | sort)
total=${#HEADERS[@]}
echo "using $CXX $("$CXX" -dumpversion 2>/dev/null), $total snippets"

# Precompile the prelude once. Parsing <bits/stdc++.h> 31 times is most of the
# runtime, and on Windows an antivirus scanning every invocation makes it minutes.
# If this fails the include below still works, only slower.
"$CXX" $STD -w -x c++-header "$TMP/prelude.h" -o "$TMP/prelude.h.gch" 2>/dev/null

fail=0; pass=0; n=0
for header in "${HEADERS[@]}"; do
	n=$((n+1))
	grep -q 'test-compiles: skip' "$header" && continue
	printf '\r[%2d/%d] %-42s' "$n" "$total" "$header"
	# Relative include plus -I. on purpose: under Git Bash an absolute path is
	# POSIX ("/c/Users/...") while the compiler it launches is a native Windows
	# binary that cannot open it, and paths inside the file are never converted.
	{ echo '#include "prelude.h"'; echo "#include \"$header\""; echo "int main(){}"; } > "$TMP/tu.cpp"
	if err=$("$CXX" $STD -fsyntax-only -w -I. "$TMP/tu.cpp" 2>&1); then
		pass=$((pass+1))
	else
		printf '\r%-52s\r' ""
		echo "FAIL $header"
		# Fall back to the raw output: a failure with no "error:" line at all
		# (compiler not found, bad flag) would otherwise be reported silently.
		msg=$(echo "$err" | grep -E "error:" | head -3)
		[ -z "$msg" ] && msg=$(echo "$err" | head -3)
		echo "$msg" | sed 's/^/      /'
		fail=$((fail+1))
	fi
done
printf '\r%-52s\r' ""

echo "$pass compile, $fail fail."
[ "$fail" -eq 0 ]
