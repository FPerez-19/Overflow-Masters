// Kahn's algorithm: topological order of a DAG. O(V + E)
// Returns an order containing all n nodes;
// if order.size() < n the graph has a cycle (no valid topological order).
vec<int> G[N];
vec<int> topological_order(int n) {
    vec<int> indegree(n, 0);
    L(u, 0, n) for (int v : G[u]) indegree[v]++;
    queue<int> q;  // priority_queue for the lexicographically smallest order
    L(u, 0, n) if (indegree[u] == 0) q.push(u);
    vec<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.pb(u);
        for (int v : G[u]) if (--indegree[v] == 0) q.push(v);
    }
    return order;  // order.size() == n  <=>  graph is a DAG
}
