/**
 * Author: Franco Perez
 * Date: 2026-09-09
 * License: CC0
 * Source: KACTL
 * Description: Polynomial hash modulo the Mersenne prime $2^{61}-1$, which fits a
 * signed ll and needs only one chain of multiplications. Takes a string or any
 * vec<ll>, so it also matches patterns over numbers (differences, coordinates).
 * get(i, len) returns a plain ll for the half-open range [i, i+len), so it
 * compares with == and works as a map key; only compare equal lengths. The fixed
 * base is fine for ICPC; on Codeforces randomise it, or someone hacks you with a
 * test built to collide under a known base.
 * Usage: StrHash h(s); h.get(i, len) == h.get(j, len);
 * Time: O(N) to build, O(1) per query
 * Status: stress-tested against direct comparison, 2000 random cases
 */
#pragma once
const ll HMOD = (1LL << 61) - 1;
struct H {
    ll x;
    H(ll v = 0) : x(((v % HMOD) + HMOD) % HMOD) {}
    static H raw(ll v) {
        H r;
        r.x = v;
        return r;
    }
    H operator+(H o) const {
        ll s = x + o.x;
        return raw(s >= HMOD ? s - HMOD : s);
    }
    H operator-(H o) const {
        ll s = x - o.x;
        return raw(s < 0 ? s + HMOD : s);
    }
    H operator*(H o) const {
        return raw(ll(__int128(x) * o.x % HMOD));
    }
};
const H HB = (ll)1e11 + 3;  // any large non-round value
struct StrHash {
    vec<H> h, pw;
    template <class T> StrHash(const T &s) : h(sz(s) + 1), pw(h) {
        pw[0] = 1;
        L(i, 0, sz(s)) {
            h [i + 1] = h[i]  * HB + s[i];
            pw[i + 1] = pw[i] * HB;
        }
    }
    ll get(int i, int len) const {
        return (h[i + len] - h[i] * pw[len]).x;
    }
};
// The template ctor is only checked once instantiated, so test-compiles needs this. // exclude-line
void _strhash_inst() { string a; vec<ll> b; StrHash(a).get(0, 0) == StrHash(b).get(0, 0); } // exclude-line
