/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Binomial coefficient mod a prime, via factorials and Fermat's
 * little theorem. Call build\_factorials() once before any query. MOD must be
 * prime for the inverse to exist.
 * Usage: Define: const int MAXN; ll power(ll, ll, ll) (see BinPow).
 * Time: O(MAXN) to build, O(\log MOD) per query
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int MAXN = 1e6 + 5; // exclude-line
ll power(ll a, ll b, ll m) { a %= m; ll r = 1; // exclude-line
    while (b > 0) { if (b & 1) r = r * a % m; // exclude-line
        a = a * a % m; b >>= 1; } return r; } // exclude-line
// ------------------------------------------------------ // exclude-line
ll factorial[MAXN];
void build_factorials() {
    factorial[0] = 1;
    L(i, 1, MAXN) factorial[i] = factorial[i - 1] * i % MOD;
}
ll binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    ll denom = factorial[k] * factorial[n - k] % MOD;
    return factorial[n] * power(denom, MOD - 2, MOD) % MOD;
}
