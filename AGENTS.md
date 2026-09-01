# Overflow-Masters — notes for agents

Competitive programming notebook. Each file in `src/<Topic>/` is a self-contained
snippet that gets included into `guide.pdf` via `\cppfile{...}` in `guide.tex`.

## Adding a snippet

1. Create the `.cpp` / `.java` file under the matching `src/<Topic>/` folder.
2. Add a `\subsection{...}` + `\cppfile{src/<Topic>/<file>}` line in `guide.tex`,
   in the right section. Section/subsection order in the PDF is defined by
   `guide.tex`, not by the filesystem.
3. Run `./compile.sh` to rebuild `guide.pdf`.

Snippets assume the shared template (`src/Details/template.cpp`): macros like
`L(i,a,b)`, `vec`, `pb`, `all`, types `ll`/`pii`, constants `oo`/`MOD`, and a
global `N` for array sizes. Don't repeat includes or `using namespace std`.

## Comment style (keep this consistent across all snippets)

A header comment block at the top of each snippet, covering:

- **What it is** — algorithm name, and the technique if not obvious.
- **Complexity** — `O(...)` in terms of the snippet's variables (V, E, n, ...).
- **What the entry point returns**, and the meaning of the return value —
  including how to read off the answer / detect the failure case
  (e.g. "if `order.size() < n` there is a cycle").
- **Preconditions** — 0-indexed vs 1-indexed, graph must be a DAG, array `N`
  large enough, etc. — only when they matter.

Inline comments only for non-obvious decision points: a line the reader might
want to tweak (e.g. "swap `queue` for `priority_queue` to get the
lexicographically smallest order"), a subtle invariant, or a non-obvious index.

Do **not** reference specific problems (no "CF 510C", no judge links). The
snippet should read as a general-purpose reference.

Example:

```cpp
// Kahn's algorithm: topological order of a DAG. O(V + E)
// Returns an order containing all n nodes;
// if order.size() < n the graph has a cycle (no valid topological order).
vec<int> G[N];
vec<int> topological_order(int n) {
    ...
    queue<int> q;  // priority_queue for the lexicographically smallest order
    ...
    return order;  // order.size() == n  <=>  graph is a DAG
}
```
