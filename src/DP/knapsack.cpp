vector<int> v(n);
vector<int> w(n);
for (auto &x : w) cin >> x;
for (auto &x : v) cin >> x;
vector<int> dp(m + 1, 0);
for (int i = 0; i < n; i++) {
    for (int j = m; j >= w[i]; j--) {
        dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
    }
}