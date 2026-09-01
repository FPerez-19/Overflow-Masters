using ll = long long;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll factorial[MAXN];

void build_factorials() {
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
}
ll binomial_coefficient(int n, int k) {
    if (k < 0 || k > n) return 0;
    ll denom = factorial[k] * factorial[n - k] % MOD;
    return factorial[n] * exp(denom, MOD - 2) % MOD;
}
