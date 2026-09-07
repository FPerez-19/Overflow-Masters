/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Modular exponentiation by squaring. With m prime, power(a, m-2, m) is the
 * modular inverse of a. Keep m below 2 to the 31 or the products overflow.
 * Time: O(\log b)
 * Status: untested
 */
#pragma once
ll power(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
