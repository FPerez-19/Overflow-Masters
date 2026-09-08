/**
 * Author: Franco Perez
 * Date: 2026-09-09
 * License: CC0
 * Source: folklore
 * Description: Connected components of the complement graph, without ever
 * building it. comp[u] gets u's component id and the count is returned. g is the
 * adjacency list of the ORIGINAL graph and every g[u] must be sorted, otherwise
 * the binary search lies and the answer is wrong with no warning.
 * Usage: Define: L(i, 0, n) sort(all(g[i])); before calling.
 * Time: O((V + E) \log V)
 * Status: stress-tested against a brute force, 4000 random graphs
 */
#pragma once
int complement_components(int n, const vec<vec<int>> &g, vec<int> &comp) {
    comp.assign(n, -1);
    set<int> notVis;
    L(i, 0, n) notVis.insert(i);
    int id = 0;
    L(s, 0, n) {
        if (!notVis.count(s)) continue;
        comp[s] = id;
        notVis.erase(s);
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            auto it = notVis.begin();
            while (it != notVis.end()) {
                int ch = *it;
                // No edge in g means there IS one in the complement.
                if (binary_search(all(g[u]), ch)) {
                    it++;
                    continue;
                }
                comp[ch] = id;
                q.push(ch);
                it = notVis.erase(it);
            }
        }
        id++;
    }
    return id;
}
