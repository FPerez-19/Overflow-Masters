const int N = 10;
int G[N][N];
L(k, 0, n)
    L(i, 0, n)
        L(j, 0, n)
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);