/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Tarjan's low-link pass over an undirected graph: prints every
 * bridge and fills ap[u] = 1 for every articulation point. Set root before each
 * call and run it once per connected component. Multi-edges break the v == p
 * check: compare edge ids instead if the graph has them.
 * Usage: Define: const int N; root = s; dfs(s);
 * Time: O(V + E)
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int N = 2e5 + 5; // exclude-line
// ------------------------------------------------------ // exclude-line
vec<int> G[N];
vec<int> dfs_low(N, -1), dfs_num(N, -1), ap(N, 0);
int dfs_count = 0;
int root = -1;
void dfs(int u, int p = -1) {
    dfs_low[u] = dfs_num[u] = dfs_count++;
    int child = 0;
    for (int v : G[u]) {
        if (v == p) continue;
        if (dfs_num[v] == -1) {
            child++;
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if (dfs_low[v] > dfs_num[u]) {
                cout << "Bridge " << u << " -> " << v << "\n";
            }
            if (dfs_low[v] >= dfs_num[u]) ap[u] = 1;
        } else
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    if (u == root) ap[u] = child > 1;
}
