// B - Blackout on the Neural Grid: solve A x = b over GF(2), A = I + adjacency
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
int main() {
    int N, M, Q;
    if (!(cin >> N >> M >> Q)) return 0;
    const int W = (2 * N + 63) / 64;          // N coeff bits + N identity bits
    vector<u64> A((size_t)N * W, 0);
    auto setbit = [&](int r, int c) { A[(size_t)r * W + (c >> 6)] ^= 1ULL << (c & 63); };
    for (int i = 0; i < N; i++) { setbit(i, i); setbit(i, N + i); }
    for (int e = 0; e < M; e++) {
        int u, v; cin >> u >> v; --u; --v;
        setbit(u, v); setbit(v, u);
    }
    // Gauss-Jordan on [A | I] -> [R | T];  y = T*b solves R x = y
    vector<int> piv;
    {
        int r = 0;
        for (int c = 0; c < N && r < N; c++) {
            int pr = -1;
            for (int i = r; i < N; i++)
                if ((A[(size_t)i * W + (c >> 6)] >> (c & 63)) & 1) { pr = i; break; }
            if (pr < 0) continue;
            for (int k = 0; k < W; k++) swap(A[(size_t)r * W + k], A[(size_t)pr * W + k]);
            u64 *prow = &A[(size_t)r * W];
            for (int i = 0; i < N; i++) {
                if (i == r) continue;
                if (!((A[(size_t)i * W + (c >> 6)] >> (c & 63)) & 1)) continue;
                u64 *row = &A[(size_t)i * W];
                for (int k = 0; k < W; k++) row[k] ^= prow[k];
            }
            piv.push_back(c); r++;
        }
    }
    const int rk = (int)piv.size();
    // TT[j] = column j of T, so y = T*b = XOR of TT[j] over set bits of b
    const int WS = (N + 63) / 64;
    vector<u64> TT((size_t)N * WS, 0);
    for (int i = 0; i < N; i++) {
        const u64 *er = &A[(size_t)i * W];
        for (int j = 0; j < N; j++)
            if ((er[(N + j) >> 6] >> ((N + j) & 63)) & 1) TT[(size_t)j * WS + (i >> 6)] |= 1ULL << (i & 63);
    }
    vector<u64> y(WS, 0), b(WS, 0);
    string tok;
    for (int qi = 0; qi < Q; qi++) {
        fill(b.begin(), b.end(), 0);
        int pos = 0;
        while (pos < N) {                 // accepts "0101" and "0 1 0 1"
            cin >> tok;
            for (char c : tok) {
                if (pos >= N) break;
                if (c == '0') b[pos >> 6] |= 1ULL << (pos & 63);   // b = 1 XOR state
                pos++;
            }
        }
        fill(y.begin(), y.end(), 0);
        for (int j = 0; j < N; j++)
            if ((b[j >> 6] >> (j & 63)) & 1) {
                const u64 *tr = &TT[(size_t)j * WS];
                for (int k = 0; k < WS; k++) y[k] ^= tr[k];
            }
        bool ok = true;                   // non-pivot rows of R must give y = 0
        for (int i = rk; i < N; i++)
            if ((y[i >> 6] >> (i & 63)) & 1) { ok = false; break; }
        if (!ok) { cout << "-1\n"; continue; }
        vector<int> sol;                  // free variables = 0, so x[piv[i]] = y[i]
        for (int i = 0; i < rk; i++)
            if ((y[i >> 6] >> (i & 63)) & 1) sol.push_back(piv[i] + 1);
        cout << sol.size();
        for (int v : sol) cout << ' ' << v;
        cout << "\n";
    }
}
