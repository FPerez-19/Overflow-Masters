/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: First n+1 Catalan numbers mod MOD by the convolution recurrence.
 * They count balanced bracket sequences, binary trees with n nodes, and
 * triangulations of an (n+2)-gon.
 * Time: O(N^2)
 * Status: untested
 */
#pragma once
vec<ll> catalan(int n) {
    vec<ll> c(n + 1, 0);
    c[0] = 1;
    if (n >= 1) c[1] = 1;
    L(i, 2, n + 1) {
        L(j, 0, i) {
            c[i] += c[j] * c[i - j - 1] % MOD;
            if (c[i] >= MOD) c[i] -= MOD;
        }
    }
    return c;
}
