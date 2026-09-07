/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: Eratosthenes
 * Description: Sieve of Eratosthenes: after build(n), comp[x] is 1 exactly when
 * x is composite, so x >= 2 is prime when comp[x] is 0.
 * Usage: Define: const int N > n.
 * Time: O(N \log \log N)
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int N = 1e6 + 5; // exclude-line
// ------------------------------------------------------ // exclude-line
bool comp[N];
void build_sieve(int n) {
    L(x, 2, n + 1) {
        if (comp[x]) continue;
        for (int u = 2 * x; u <= n; u += x) comp[u] = 1;
    }
}
