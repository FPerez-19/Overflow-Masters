/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: Kahn
 * Description: Topological order of a DAG over the global adjacency list G.
 * Returns an order with all n nodes; if order.size() < n the graph has a cycle
 * and no topological order exists.
 * Usage: Define: const int N; swap queue for priority_queue to get the
 * lexicographically smallest order.
 * Time: O(V + E)
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int N = 2e5 + 5; // exclude-line
// ------------------------------------------------------ // exclude-line
vec<int> G[N];
vec<int> topological_order(int n) {
    vec<int> indegree(n, 0);
    L(u, 0, n) for (int v : G[u]) indegree[v]++;
    queue<int> q;
    L(u, 0, n) if (indegree[u] == 0) q.push(u);
    vec<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.pb(u);
        for (int v : G[u]) if (--indegree[v] == 0) q.push(v);
    }
    return order;
}
