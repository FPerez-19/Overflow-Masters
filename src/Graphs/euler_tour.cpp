struct edge {
    int y;
    list<edge>::iterator rev;  // NO DIRIGIDOS: iterador para arista reversa
    edge(int y) : y(y) {}
};

list<edge> g[N];

void add_edge(int a, int b) {
    g[a].push_front(edge(b));
    auto ia = g[a].begin();    // NO DIRIGIDOS
    g[b].push_front(edge(a));  // NO DIRIGIDOS
    auto ib = g[b].begin();    // NO DIRIGIDOS
    ia->rev = ib;              // NO DIRIGIDOS
    ib->rev = ia;              // NO DIRIGIDOS
}

vec<int> p;

void go(int x) {
    while (SZ(g[x])) {
        int y = g[x].front().y;
        g[y].erase(g[x].front().rev);  // NO DIRIGIDOS: eliminar
        g[x].pop_front();
        go(y);
    }
    p.pb(x);
}

vec<int> get_path(int x) {
    p.clear();
    go(x);
    reverse(ALL(p));
    return p;
}

void solve() {
    int n, m;
    cin >> n >> m;

    // vec<int> inDeg(n, 0), outDeg(n, 0);  // DIRIGIDOS
    vec<int> deg(n, 0);  // NO DIRIGIDOS

    L(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        add_edge(a, b);
        // inDeg[b]++; // DIRIGIDOS
        // outDeg[a]++; // DIRIGIDOS
        deg[a]++;  // NO DIRIGIDOS
        deg[b]++;  // NO DIRIGIDOS
    }

    // DIRIGIDOS (camino euleriano):
    // Nodo 0: outDeg[0] = inDeg[0] + 1 (nodo inicial)
    // Nodo n-1: inDeg[n-1] = outDeg[n-1] + 1 (nodo final)
    // Resto: inDeg[i] = outDeg[i]
    // L(i, 1, n - 1) {
    //     if (inDeg[i] != outDeg[i]) {
    //         cout << "IMPOSSIBLE\n";
    //         return;
    //     }
    // }
    // if (outDeg[0] != inDeg[0] + 1 || inDeg[n - 1] != outDeg[n - 1] + 1) {
    //     cout << "IMPOSSIBLE\n";
    //     return;
    // }

    // NO DIRIGIDOS: verificar que todos los grados sean pares
    L(i, 0, n) {
        if (deg[i] % 2) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    vec<int> path = get_path(0);

    if (SZ(path) != m + 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (auto x : path) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
}