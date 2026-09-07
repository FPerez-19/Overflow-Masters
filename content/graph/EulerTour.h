/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Eulerian path/circuit on an undirected multigraph, erasing each
 * edge as it is used (the list iterator rev points at the twin). get\_path(s)
 * returns m+1 nodes when a tour exists, fewer when the graph is not connected.
 * Needs every degree even for a circuit, or exactly two odd and start at one of
 * them. For directed graphs drop the rev bookkeeping and ask outDeg[s] =
 * inDeg[s]+1, inDeg[t] = outDeg[t]+1, and equal everywhere else.
 * Usage: Define: const int N; add_edge(a, b); get_path(0);
 * Time: O(V + E)
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int N = 2e5 + 5; // exclude-line
// ------------------------------------------------------ // exclude-line
struct edge {
    int y;
    list<edge>::iterator rev;
    edge(int y) : y(y) {}
};
list<edge> g[N];
vec<int> p;

void add_edge(int a, int b) {
    g[a].push_front(edge(b));
    auto ia = g[a].begin();
    g[b].push_front(edge(a));
    auto ib = g[b].begin();
    ia->rev = ib;
    ib->rev = ia;
}
void go(int x) {
    while (sz(g[x])) {
        int y = g[x].front().y;
        g[y].erase(g[x].front().rev);
        g[x].pop_front();
        go(y);
    }
    p.pb(x);
}
vec<int> get_path(int x) {
    p.clear();
    go(x);
    reverse(all(p));
    return p;
}
