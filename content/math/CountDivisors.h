/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Number of divisors of every number below MAXN at once, by adding
 * one to every multiple of every i. Use it when you need the counts for a whole
 * range; for a single n, trial division up to sqrt(n) is faster.
 * Usage: Define: const int MAXN.
 * Time: O(N \log N)
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int MAXN = 1000001; // exclude-line
// ------------------------------------------------------ // exclude-line
int ndiv[MAXN];
void count_divisors() {
    L(i, 1, MAXN)
        for (int j = i; j < MAXN; j += i) ndiv[j]++;
}
