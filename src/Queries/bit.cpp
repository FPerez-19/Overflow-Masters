#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

const int MAXN = 200000;
ll BIT[MAXN + 1];  // Array para el BIT
ll arr[MAXN + 1];  // Array original

void update(int idx, ll delta, int n) {
    while (idx <= n) {
        BIT[idx] += delta;
        idx += idx & -idx;
    }
}

ll query(int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

ll rangeQuery(int L, int R) { return query(R) - query(L - 1); }

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i], n);  // init
    }

    while (q--) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            ll delta = b - arr[a];
            arr[a] = b;
            update(a, delta, n);
        } else {
            cout << rangeQuery(a, b) << "\n";
        }
    }

    return 0;
}
