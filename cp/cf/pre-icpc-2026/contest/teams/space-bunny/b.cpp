#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
int main() {
    int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
    int AW = (N + 63) / 64;
    int W = 2 * AW;                    // A part in [0, AW*64), transform T in [AW*64, 2*AW*64)
    vector<u64> A((size_t)N * W, 0);
    auto setbit = [&](int r, int c) { A[(size_t)r * W + (c >> 6)] ^= 1ULL << (c & 63); };
    for (int i = 0; i < N; i++) setbit(i, i);
    for (int e = 0; e < M; e++) {
        int u, v; scanf("%d %d", &u, &v); --u; --v;
        setbit(u, v); setbit(v, u);
    }
    for (int i = 0; i < N; i++) setbit(i, AW * 64 + i);
    vector<int> pivcol;
    int rank = 0;
    for (int col = 0; col < N && rank < N; col++) {
        int w = col >> 6, bt = col & 63;
        int pr = -1;
        for (int r = rank; r < N; r++) if ((A[(size_t)r * W + w] >> bt) & 1ULL) { pr = r; break; }
        if (pr < 0) continue;
        if (pr != rank) for (int j = 0; j < W; j++) swap(A[(size_t)rank * W + j], A[(size_t)pr * W + j]);
        u64 *prow = &A[(size_t)rank * W];
        for (int r = rank + 1; r < N; r++) {
            u64 *row = &A[(size_t)r * W];
            if ((row[w] >> bt) & 1ULL) for (int j = w; j < W; j++) row[j] ^= prow[j];
        }
        pivcol.push_back(col); rank++;
    }
    bool zeroTail = true;
    for (int r = rank; r < N && zeroTail; r++)
        for (int j = 0; j < AW; j++) if (A[(size_t)r * W + j]) { zeroTail = false; break; }
    vector<u64> b(AW, 0), c(AW, 0), xw(AW, 0);
    for (int q = 0; q < Q; q++) {
        fill(b.begin(), b.end(), 0);
        for (int i = 0; i < N; i++) { char ch; if (scanf(" %c", &ch) != 1) return 0; if (ch == '0') b[i >> 6] |= 1ULL << (i & 63); }
        fill(c.begin(), c.end(), 0);
        for (int i = 0; i < N; i++) {
            const u64 *row = &A[(size_t)i * W];
            u64 par = 0;
            for (int j = 0; j < AW; j++) par ^= __builtin_parityll(row[AW + j] & b[j]);
            if (par) c[i >> 6] |= 1ULL << (i & 63);
        }
        bool good = zeroTail;
        for (int r = rank; r < N && good; r++)
            if ((c[r >> 6] >> (r & 63)) & 1ULL) good = false;
        if (!good) { printf("-1\n"); continue; }
        fill(xw.begin(), xw.end(), 0);
        for (int i = rank - 1; i >= 0; i--) {
            int col = pivcol[i];
            const u64 *row = &A[(size_t)i * W];
            u64 v = (c[i >> 6] >> (i & 63)) & 1ULL;
            for (int j = col >> 6; j < AW; j++) {
                u64 mask = ~0ULL;
                if (j == (col >> 6)) mask = ~0ULL << ((col & 63) + 1);
                v ^= __builtin_parityll(row[j] & xw[j] & mask);
            }
            if (v) xw[col >> 6] |= 1ULL << (col & 63);
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) if ((xw[i >> 6] >> (i & 63)) & 1ULL) cnt++;
        printf("%d", cnt);
        for (int i = 0; i < N; i++) if ((xw[i >> 6] >> (i & 63)) & 1ULL) printf(" %d", i + 1);
        printf("\n");
    }
    return 0;
}
