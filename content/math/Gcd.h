/**
 * Author: Franco Perez
 * Date: 2026-09-09
 * License: CC0
 * Source: Euclides
 * Description: Greatest common divisor by Euclid's algorithm, iterative so there
 * is no recursion to blow. Replaces GCC's \_\_gcd, which is an extension and may
 * not exist on the contest machines. Not named gcd on purpose: C++17 already has
 * std::gcd and using namespace std makes the call ambiguous. GCD(0, 0) is 0; for
 * negatives take the absolute value first.
 * Time: O(\log \min(a, b))
 * Status: stress-tested against a brute force, see tests/Gcd.cpp
 */
#pragma once
ll GCD(ll a, ll b) {
    while (b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
