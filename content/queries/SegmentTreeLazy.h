/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Segment tree with lazy assignment on whole ranges, answering the
 * maximum. Three lines marked below turn it into min, or into sum -- they change
 * together or the answers are silently wrong. lazy uses -1 as "no pending
 * assignment", so -1 cannot be a stored value.
 * Usage: SegTreeLazy st(a); st.update(l, r, v); st.query(l, r);
 * Time: O(\log N) per query or update
 * Status: stress-tested against a brute force, see tests/SegmentTreeLazy.cpp
 */
#pragma once
struct SegTreeLazy {
    int n;
    vec<int> A, st, lazy;
    const int neutral = INT_MIN;                     // min: INT_MAX | suma: 0
    int conquer(int a, int b) { return max(a, b); }  // min: min | suma: a + b
    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }
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
    void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {
            st[p] = lazy[p];  // suma: lazy[p] * (R - L + 1)
            if (L != R) lazy[l(p)] = lazy[r(p)] = lazy[p];
            lazy[p] = -1;
        }
    }
    int query(int p, int L, int R, int i, int j) {
        if (i > j || L > j || R < i) return neutral;
        propagate(p, L, R);
        if (L >= i && R <= j) return st[p];
        int m = L + (R - L) / 2;
        return conquer(query(l(p), L, m, i, j), query(r(p), m + 1, R, i, j));
    }
    void update(int p, int L, int R, int i, int j, int v) {
        propagate(p, L, R);  // antes del corte, o el padre lee un hijo sin propagar
        if (i > j || L > j || R < i) return;
        if (L >= i && R <= j) {
            lazy[p] = v;
            propagate(p, L, R);
        } else {
            int m = L + (R - L) / 2;
            update(l(p), L, m, i, j, v);
            update(r(p), m + 1, R, i, j, v);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }
    SegTreeLazy(int sz) : n(sz), st(4 * n), lazy(4 * n, -1) {}
    SegTreeLazy(const vec<int> &init) : SegTreeLazy((int)init.size()) {
        A = init;
        build(1, 0, n - 1);
    }
    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }
    int query(int i, int j) { return query(1, 0, n - 1, i, j); }
};
