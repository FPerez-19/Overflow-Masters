/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Minimum spanning tree by sorting the edge list. Returns the cost;
 * if the graph is disconnected it returns the cost of the spanning forest, so
 * check uf.numSets == 1 when that matters.
 * Usage: Define: struct UFDS (see Union-Find). vec<Edge> el; kruskal(V, el);
 * Time: O(E \log E)
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
struct UFDS { // exclude-line
    vec<int> p, size; int numSets, n; // exclude-line
    UFDS(int n) : p(n), size(n, 1), n(n) { // exclude-line
        for (int i = 0; i < n; i++) p[i] = i; numSets = n; } // exclude-line
    int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); } // exclude-line
    void join(int i, int j) { int a = find(i), b = find(j); // exclude-line
        if (a != b) { if (size[b] > size[a]) swap(a, b); // exclude-line
            p[b] = a; size[a] += size[b]; numSets--; } } // exclude-line
}; // exclude-line
// ------------------------------------------------------ // exclude-line
struct Edge {
    int w, u, v;
    bool operator<(const Edge &o) const { return w < o.w; }
};
ll kruskal(int V, vec<Edge> &el) {
    sort(all(el));
    UFDS uf(V);
    ll cost = 0;
    for (auto &[w, u, v] : el) {
        if (uf.find(u) == uf.find(v)) continue;
        cost += w;
        uf.join(u, v);
        if (uf.numSets == 1) break;
    }
    return cost;
}
