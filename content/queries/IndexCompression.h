/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Maps the values of an array onto 0..k-1 keeping their order, so
 * they can index a BIT or a segment tree. of(e) is the compressed index of e,
 * at(i) the original value, sz how many distinct values there were.
 * Usage: Index<int> idx(a); idx.of(a[i]);
 * Time: O(N \log N) to build, O(\log N) per lookup
 * Status: untested
 */
#pragma once
template <class T>
struct Index {
    vec<T> d;
    int sz;
    Index(vec<T> &a) : d(all(a)) {
        sort(all(d));
        d.erase(unique(all(d)), end(d));
        sz = (int)d.size();
    }
    int of(T e) { return lower_bound(all(d), e) - begin(d); }
    T at(int i) { return d[i]; }
};
