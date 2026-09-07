/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Length of the longest common subsequence of two strings (not
 * substring: the characters need not be contiguous).
 * Time: O(NM)
 * Status: untested
 */
#pragma once
int lcs(string &s1, string &s2) {
    int m = sz(s1), n = sz(s2);
    vec<vec<int>> dp(m + 1, vec<int>(n + 1, 0));
    L(i, 1, m + 1) L(j, 1, n + 1) {
        if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
    return dp[m][n];
}
