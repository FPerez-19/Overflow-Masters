/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: Levenshtein
 * Description: Minimum number of insertions, deletions and replacements that
 * turn s1 into s2. Row 0 and column 0 are the cost of building a string from
 * nothing.
 * Time: O(NM)
 * Status: untested
 */
#pragma once
int editDistance(string &s1, string &s2) {
    int n = sz(s1), m = sz(s2);
    vec<vec<int>> dp(n + 1, vec<int>(m + 1));
    L(i, 0, n + 1) dp[i][0] = i;
    L(j, 0, m + 1) dp[0][j] = j;
    L(i, 1, n + 1) L(j, 1, m + 1) {
        if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1];
        else
            dp[i][j] = 1 + min({dp[i - 1][j],        // deletion
                                dp[i][j - 1],        // insertion
                                dp[i - 1][j - 1]});  // replacement
    }
    return dp[n][m];
}
