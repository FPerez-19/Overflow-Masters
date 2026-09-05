/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Minimum spanning tree grown from node 0 with a priority queue.
 * Returns the cost; taken[v] tells which nodes ended up in the tree, so if some
 * are still 0 the graph was disconnected. al must hold both directions.
 * Usage: vec<vec<pii>> al(V); al[u].emplace_back(v, w); al[v].emplace_back(u, w); prim(V, al);
 * Time: O(E \log V)
 * Status: untested
 */
#pragma once
ll prim(int V, vec<vec<pii>> &al) {
    vec<int> taken(V, 0);
    priority_queue<pii, vec<pii>, greater<pii>> pq;
    auto process = [&](int u) {
        taken[u] = 1;
        for (auto &[v, w] : al[u])
            if (!taken[v]) pq.emplace(w, v);
    };
    process(0);
    ll cost = 0;
    int num_taken = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (taken[u]) continue;
        cost += w;
        process(u);
        if (++num_taken == V - 1) break;
    }
    return cost;
}
