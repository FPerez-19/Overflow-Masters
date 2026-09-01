struct SCC {
    int n;
    vec<vec<int>> G, G2;
    vec<int> order, sccId, vi;
    vec<vec<int>> components;
    int sccCount;

    SCC(int n) : n(n) {
        G.assign(n, vec<int>());
        G2.assign(n, vec<int>());
        sccId.assign(n, -1);
        sccCount = 0;
    }

    void addEdge(int u, int v) {
        G[u].pb(v);
        G2[v].pb(u);
    }

    void dfs1(int u) {
        vi[u] = 1;
        for (int v : G[u]) {
            if (!vi[v]) dfs1(v);
        }
        order.pb(u);
    }

    void dfs2(int u, int id) {
        vi[u] = 1;
        sccId[u] = id;
        components[id].pb(u);
        for (int v : G2[u]) {
            if (!vi[v]) dfs2(v, id);
        }
    }

    void findSCC() {
        vi.assign(n, 0);
        order.clear();
        L(i, 0, n) {
            if (!vi[i]) dfs1(i);
        }

        vi.assign(n, 0);
        sccCount = 0;
        components.clear();

        reverse(ALL(order));
        for (int u : order) {
            if (!vi[u]) {
                components.pb(vec<int>());
                dfs2(u, sccCount++);
            }
        }
    }

    vec<vec<int>> getCondensedGraph() {
        vec<vec<int>> sccGraph(sccCount);
        set<pii> edges;

        L(u, 0, n) {
            for (int v : G[u]) {
                int fromScc = sccId[u], toScc = sccId[v];
                if (fromScc != toScc &&
                    edges.find({fromScc, toScc}) == edges.end()) {
                    sccGraph[fromScc].pb(toScc);
                    edges.insert({fromScc, toScc});
                }
            }
        }
        return sccGraph;
    }

    int getSCCId(int u) { return sccId[u]; }
    vec<int> getSCC(int i) { return components[i]; }
    int getCount() { return sccCount; }
};