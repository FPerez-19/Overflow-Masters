struct UFDS {
    vec<int> p, size;
    int numSets, n;
    UFDS(int n) : p(n), size(n, 1), n(n) {
        for (int i = 0; i < n; i++) p[i] = i;
        numSets = n;
    }
    int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
    void join(int i, int j) {
        int a = find(i), b = find(j);
        if (a != b) {
            if (size[b] > size[a]) swap(a, b);
            p[b] = a;
            size[a] += size[b];
            numSets--;
        }
    }
};