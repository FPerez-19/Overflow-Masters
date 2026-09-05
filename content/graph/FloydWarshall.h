/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: All-pairs shortest paths over the global matrix G, rewritten in
 * place. Initialise G[i][i] = 0, G[i][j] = weight, and oo where there is no
 * edge; keep oo small enough that oo + oo does not overflow.
 * Usage: Define: const int N; fill G before calling.
 * Time: O(V^3)
 * Status: untested
 */
#pragma once
// --- deps (drop what your solution already defines) --- // exclude-line
const int N = 505; // exclude-line
// ------------------------------------------------------ // exclude-line
int G[N][N];
void floyd(int n) {
    L(k, 0, n)
        L(i, 0, n)
            L(j, 0, n)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
