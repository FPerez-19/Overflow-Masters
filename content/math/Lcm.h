/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Least common multiple. Divides before multiplying, so a and b can
 * be up to 9e18 / max(a, b) without overflowing. Not named lcm on purpose: C++17
 * already has std::lcm and using namespace std makes the call ambiguous.
 * Time: O(\log \min(a, b))
 * Status: untested
 */
#pragma once
ll LCM(ll a, ll b) { return a / __gcd(a, b) * b; }
