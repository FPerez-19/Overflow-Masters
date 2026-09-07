# Overflow-Masters — notes for agents

ICPC team notebook. Each file in `content/<chapter>/` is a self-contained snippet that
gets printed into `notebook.pdf`. The build system is KACTL's: `content/tex/notebook.sty`
plus `content/tex/preprocessor.py`, driven by `make`.

## Adding a snippet

1. Create `content/<chapter>/YourThing.h` with a doc header (see below) and `#pragma once`.
2. Add `\nbimport{YourThing.h}` to that chapter's `chapter.tex`. That file is the single
   source of truth for what gets printed and in what order — the filesystem is not.
3. `make showexcluded` must print nothing.
4. `make test-compiles` must pass. `make fast` to see the page.

New chapter: create `content/<name>/chapter.tex` starting with `\chapter{Name}` and add
`\nbchapter{<name>}` to `content/notebook.tex`.

## The doc header

```cpp
/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: where it came from, or "folklore"
 * Description: What it does, what it returns, how to read off the answer and how to
 * detect the failure case, plus any precondition that matters (0- vs 1-indexed, DAG
 * only, N large enough).
 * Usage: what the caller must define or call first.
 * Time: O(V + E)
 * Status: untested
 */
```

- `Author` and `Description` are required; anything else fails the build.
- Only the known fields (`Author`, `Date`, `Description`, `Source`, `Time`, `Memory`,
  `License`, `Status`, `Usage`, `Details`) may appear as `Word:` at the start of a line —
  the preprocessor reads any such line as a field name and errors on unknown ones.
- `Description` is LaTeX text: write `\_` for an underscore, avoid `^ ~ # $ % &`.
  `Usage` is escaped as code: write underscores plainly there.
- `Time` is LaTeX math (`O(N \log N)`). **If you are not sure of the bound, write
  `Time: unknown`** — a wrong bound in a notebook misleads someone under time pressure.
- Do **not** reference specific problems (no "CF 510C", no judge links).

Inline comments only for non-obvious decision points: a line the reader might want to
tweak, a subtle invariant, a non-obvious index.

## Conventions

Snippets are written against `content/contest/Template.cpp`: `L(i,j,n)`, `RI(i,j,n)`,
`sz(x)`, `all(x)`, `vec`, `pb`, `ll`, `ld`, `pii`, `pll`, `MOD`, `oo`. Never repeat
includes or `using namespace std`, and never re-declare something the template already
defines (`MOD` and `oo` above all) — it is a redefinition error under `test-compiles`.

Every snippet must compile standalone; CI fails the build otherwise. When a snippet needs
solution-level declarations to do that, put them in a deps block where every line ends in
`// exclude-line`, which keeps them for the compiler while dropping them from both the
printed page and the content hash. State what the caller must define in `Usage:` instead.

Each snippet prints a six-character hash of its own tokens so it can be verified after
being typed under contest conditions. Anything that changes a snippet's tokens changes its
hash — that is intended, but it means cosmetic rewrites are not free.
