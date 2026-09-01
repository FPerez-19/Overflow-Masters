ll count(const vec<ll>& a) {
    ll sum = 0;
    for (ll x : a) {
        sum += __builtin_popcountll(x);
    }
    return sum;
}
// ANOTHER IMPLEMENTATION
ll ans = 0;
L(i, 0, n) {
    cin >> a[i];
    L(bit, 0, 62) {
        if (a[i] & (1ll << bit)) ans++;
    }
}