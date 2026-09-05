/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Total number of set bits over an array. The builtin is one
 * instruction; the loop below is the version you write when you need the count
 * per bit position (for the classic "sum over pairs, bit by bit" trick).
 * Time: O(N), or O(62N) bit by bit
 * Status: untested
 */
#pragma once
ll popcount_sum(const vec<ll> &a) {
    ll sum = 0;
    for (ll x : a) sum += __builtin_popcountll(x);
    return sum;
}
vec<ll> bits_per_position(const vec<ll> &a) {
    vec<ll> cnt(62, 0);
    for (ll x : a)
        L(bit, 0, 62) if (x & (1ll << bit)) cnt[bit]++;
    return cnt;
}
