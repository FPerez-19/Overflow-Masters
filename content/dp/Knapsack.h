/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: 0/1 knapsack: best value with total weight at most cap, each item
 * usable once. The inner loop runs downwards, which is what stops an item from
 * being taken twice; run it upwards and you get the unbounded version.
 * Usage: knapsack(cap, w, v) with w and v the same length.
 * Time: O(N \cdot cap)
 * Status: untested
 */
#pragma once
int knapsack(int cap, vec<int> &w, vec<int> &v) {
    vec<int> dp(cap + 1, 0);
    L(i, 0, sz(w))
        for (int j = cap; j >= w[i]; j--)
            dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
    return dp[cap];
}
