/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Segment tree with point updates and range queries, 0-indexed and
 * inclusive on both ends. As written it sums; change conquer and neutral
 * together for min, max or gcd (neutral is what an empty range must return).
 * Usage: SegTree st(a); st.update(i, v); st.query(l, r);
 * Time: O(N) to build, O(\log N) per query or update
 * Status: stress-tested against a brute force, 300 random cases
 */
#pragma once
struct SegTree {
    int n;
    vec<ll> A, st;
    const ll neutral = 0;
    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }
    ll conquer(ll a, ll b) { return a + b; }
    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            int m = L + (R - L) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }
    ll query(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return neutral;
        if (L >= i && R <= j) return st[p];
        int m = L + (R - L) / 2;
        return conquer(query(l(p), L, m, i, j), query(r(p), m + 1, R, i, j));
    }
    void update(int p, int L, int R, int i, ll v) {
        if (L == R) {
            st[p] = v;
            return;
        }
        int m = L + (R - L) / 2;
        if (i <= m)
            update(l(p), L, m, i, v);
        else
            update(r(p), m + 1, R, i, v);
        st[p] = conquer(st[l(p)], st[r(p)]);
    }
    SegTree(const vec<ll> &init) : n(sz(init)), A(init), st(4 * n) {
        build(1, 0, n - 1);
    }
    ll query(int i, int j) { return query(1, 0, n - 1, i, j); }
    void update(int i, ll v) { update(1, 0, n - 1, i, v); }
};
