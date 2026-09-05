/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Disjoint set union with path compression and union by size.
 * find(i) returns the representative, join(i, j) merges, numSets counts the
 * components left, size[find(i)] is the size of i's component.
 * Usage: UFDS uf(n); uf.join(a, b); uf.find(a) == uf.find(b);
 * Time: O(\alpha(N)) amortised per operation
 * Status: untested
 */
#pragma once
struct UFDS {
    vec<int> p, size;
    int numSets, n;
    UFDS(int n) : p(n), size(n, 1), n(n) {
        for (int i = 0; i < n; i++) p[i] = i;
        numSets = n;
    }
    int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
    void join(int i, int j) {
        int a = find(i), b = find(j);
        if (a != b) {
            if (size[b] > size[a]) swap(a, b);
            p[b] = a;
            size[a] += size[b];
            numSets--;
        }
    }
};
