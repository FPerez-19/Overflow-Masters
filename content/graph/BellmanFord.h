/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Shortest paths from source with negative weights allowed, on the
 * adjacency list g of {to, cost}. Leaves the answer in d; d[v] == INT\_MAX means
 * unreachable. Does not report negative cycles: if one more relaxation round
 * still lowers a distance, there is one.
 * Usage: vec<vec<pii>> g(n); vec<int> d; bellmanFord(n, s, g, d);
 * Time: O(V E)
 * Status: untested
 */
#pragma once
void bellmanFord(int n, int source, vec<vec<pii>> &g, vec<int> &d) {
    d.assign(n, INT_MAX);
    d[source] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto &[a, c] : g[j]) {
                if (d[j] != INT_MAX && d[a] > d[j] + c) {
                    d[a] = d[j] + c;
                }
            }
        }
    }
}
