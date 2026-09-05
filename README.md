# Overflow-Masters

ICPC team reference notebook, Universidad ORT Uruguay.

Built on [KACTL](https://github.com/kth-competitive-programming/kactl)'s organization and
build system. Every snippet is printed with a description, a time complexity, and a six-character
content hash you can check against what you typed during a contest.

## Building

```sh
make notebook        # two passes, so the table of contents settles
make fast            # one pass, for quick iteration
make test-compiles   # every snippet must compile standalone
make showexcluded    # files no chapter.tex imports
```

The result is `notebook.pdf`. It is **not** committed — CI builds it on every push to
`main` and publishes it as a release, so the current build is always one click away:

**[Download the latest notebook.pdf](https://github.com/FPerez-19/Overflow-Masters/releases/latest/download/notebook.pdf)**

Every push to `main` also publishes its own numbered release (`v1`, `v2`, ...), so you can
fetch the exact PDF the team carried to a given contest. The twenty most recent builds are
kept, and each CI run also attaches the PDF as an artifact if you need a branch build.

### Requirements

- A TeX distribution with `pdflatex` and the `extreport` class
  (`texlive-latex-extra` + `texlive-plain-generic` on Debian/Ubuntu, MiKTeX on Windows).
- Python 3, for the source preprocessor.
- **`-shell-escape` must be enabled.** The build calls the preprocessor through
  `\write18`. If your distribution restricts it, the build fails with an error that does
  not name the cause — that is the first thing to check.
- GNU `g++` on PATH for the content hashes (Git Bash's works; Apple's `clang` does not
  accept `-fpreprocessed`, so on macOS `brew install gcc` and use `CXX=g++-16`).
- The `upquote` package and `T1` font encoding, so code prints straight `'` rather than a
  typographic `’`. Without them, code copied off the page is invalid as typed.

## Verifying a snippet during a contest

Each snippet prints a six-character hash of its own code. Comments and all whitespace are
ignored, so only the tokens matter — skip the comments and indent however you like.

1. Type the snippet into its own file, `Dijkstra.cpp`, containing **nothing else**. No
   `#include`, no template, no `main`; any extra token changes the hash.
2. Hash it and compare to the page:

```sh
sh content/contest/hash.sh < Dijkstra.cpp
```

3. Only once it matches, read it into your solution (`:r Dijkstra.cpp` in vim) and *then*
   adapt it. Adapt first and the hash can never match.

A mismatch tells you *that* you mistyped, not where. Check the printed line count first,
then re-read the dense lines.

## Layout

```
content/
  notebook.tex          document root; lists the chapters in print order
  tex/
    notebook.sty        3-column layout and the \nbimport machinery
    preprocessor.py     parses doc headers, strips comments, computes hashes
  contest/              template, hash.sh, policy-based structures, Java
  graph/  dp/  search/  queries/  math/  strings/
scripts/test-compiles.sh  compiles every snippet standalone
```

Each chapter directory holds a `chapter.tex` that lists its files, and that file is the
single source of truth for what gets printed.

## Adding a snippet

1. Create `content/<chapter>/YourThing.h` with a doc header:

```cpp
/**
 * Author: Your Name
 * Date: 2026-09-05
 * License: CC0
 * Source: where it came from, or "folklore"
 * Description: What it does, what it returns, and any indexing convention.
 * Time: O(N \log N)
 * Status: untested
 */
#pragma once
```

`Author` and `Description` are required — omit either and the build fails. `Time` is LaTeX
math. **If you are not sure of the bound, write `Time: unknown`** rather than guessing; a
wrong bound in a notebook misleads someone under time pressure.

`Description` is LaTeX text: write `\_` for an underscore and avoid `^ ~ # $ % &`.
`Usage` is code: write underscores plainly there. A line of the form `Word:` inside the
comment is read as a field name, so only the fields above may start a line that way.

2. Add `\nbimport{YourThing.h}` to that chapter's `chapter.tex`.
3. `make showexcluded` — it should print nothing. Anything listed means you added a file
   and forgot to import it.
4. `make fast` and check the page.

## Conventions

Snippets are written against the macros in `content/contest/Template.cpp` — `L(i,j,n)`,
`RI(i,j,n)`, `sz(x)`, `all(x)`, `vec`, `pb`, `ll`, `ld`, `pii`, `pll`, `MOD`, `oo`. This is
deliberately **not** KACTL's `rep`/`sz`/`all`/`vi` dialect: we adopted KACTL's machinery,
not its idiom.

Every snippet compiles on its own — `make test-compiles` enforces it and CI fails the build
otherwise. Where a snippet needs solution-level declarations to do that, they sit in a block
marked `exclude-line`, which keeps them in the file for the compiler while dropping them
from both the printed page and the content hash:

```cpp
// --- deps (drop what your solution already defines) --- // exclude-line
const int N = 2e5 + 5; // exclude-line
// ------------------------------------------------------ // exclude-line
```

So you never see or type them. What the snippet needs is stated in its `Usage:` field
instead, which does print.

Compiling is not correctness: every snippet is `Status: untested` and there are no stress
tests.

## Credits

Build system from [KACTL](https://github.com/kth-competitive-programming/kactl) (KTH Royal
Institute of Technology, CC0). 
`notebook.sty`, `preprocessor.py` and `hash.sh` are lightly modified derivatives of theirs.
This notebook's contents are ours.

## License

[CC0 1.0 Universal](LICENSE) — public domain. Copy anything here without asking and
without attribution, the same way we copied from KACTL.
