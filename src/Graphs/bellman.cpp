void bellmanFord(int n, int source, vec<vec<pii>> &g, vec<int> &d) {
    d.assign(n, INT_MAX);
    d[source] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto &[a, c] : g[j]) {
                if (d[j] != INT_MAX && d[a] > d[j] + c) {
                    d[a] = d[j] + c;
                }
            }
        }
    }
}