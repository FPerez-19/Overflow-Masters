/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: Fenwick
 * Description: Prefix sums with point updates. 1-INDEXED: index 0 is unused and
 * update(0, ...) loops forever. update adds delta, it does not assign, so to set
 * a[i] = x pass x - a[i] and keep the plain array in sync.
 * Usage: Define: const int MAXN. update(i, delta, n); rangeQuery(l, r);
 * Time: O(\log N) per operation
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int MAXN = 200000; // exclude-line
// ------------------------------------------------------ // exclude-line
ll BIT[MAXN + 1];
void update(int idx, ll delta, int n) {
    while (idx <= n) {
        BIT[idx] += delta;
        idx += idx & -idx;
    }
}
ll query(int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}
ll rangeQuery(int l, int r) { return query(r) - query(l - 1); }
