/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Single-source shortest paths with non-negative weights, over the
 * global adjacency list G. dist[v] == oo means v is unreachable. oo is the
 * template's 1e9: raise it if real distances can exceed that.
 * Usage: Define: const int N; fill G[u] with {v, w}.
 * Time: O((V + E) \log V)
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int N = 2e5 + 5; // exclude-line
// ------------------------------------------------------ // exclude-line
vec<pll> G[N];
vec<ll> dijk(ll s) {
    vec<ll> dist(N, oo);
    dist[s] = 0;
    priority_queue<pll, vec<pll>, greater<pll>> pq;
    pq.push({0ll, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : G[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
