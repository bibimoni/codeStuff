#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, Q;
    if (!(cin >> N >> M >> Q)) return 0;
    int W = N + Q; // total bits per row
    int NW = (W + 63) / 64;
    vector<uint64_t> a((size_t)N * NW, 0);
    auto bit = [&](int r, int c) -> uint64_t& { return a[(size_t)r * NW + (c >> 6)]; };
    for (int i = 0; i < N; i++) bit(i, i) |= (1ULL << (i & 63));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        bit(u, v) |= (1ULL << (v & 63));
        bit(v, u) |= (1ULL << (u & 63));
    }
    vector<string> init(Q);
    for (int j = 0; j < Q; j++) {
        string s;
        while ((int)s.size() < N) { string tok; cin >> tok; for (char c : tok) if (c == '0' || c == '1') s += c; }
        init[j] = s;
    }
    // RHS: need final all 1: x solves A x = 1 + init
    for (int j = 0; j < Q; j++) {
        for (int i = 0; i < N; i++) {
            int need = 1 ^ (init[j][i] - '0');
            if (need) bit(i, N + j) |= (1ULL << ((N + j) & 63));
        }
    }
    vector<int> pivRow(N, -1);
    int row = 0;
    for (int c = 0; c < N && row < N; c++) {
        int sel = -1;
        for (int i = row; i < N; i++) {
            if ((a[(size_t)i * NW + (c >> 6)] >> (c & 63)) & 1ULL) { sel = i; break; }
        }
        if (sel == -1) continue;
        if (sel != row) {
            for (int w = 0; w < NW; w++) swap(a[(size_t)sel * NW + w], a[(size_t)row * NW + w]);
        }
        for (int i = 0; i < N; i++) if (i != row) {
            if ((a[(size_t)i * NW + (c >> 6)] >> (c & 63)) & 1ULL) {
                for (int w = 0; w < NW; w++) a[(size_t)i * NW + w] ^= a[(size_t)row * NW + w];
            }
        }
        pivRow[c] = row;
        row++;
    }
    // answer each query
    for (int j = 0; j < Q; j++) {
        bool bad = false;
        // check rows without pivot: any row i>=row with RHS bit j set
        for (int i = row; i < N; i++) {
            if ((a[(size_t)i * NW + ((N + j) >> 6)] >> ((N + j) & 63)) & 1ULL) { bad = true; break; }
        }
        if (bad) { cout << -1 << "\n"; continue; }
        vector<int> sol;
        for (int c = 0; c < N; c++) {
            if (pivRow[c] != -1) {
                int r = pivRow[c];
                if ((a[(size_t)r * NW + ((N + j) >> 6)] >> ((N + j) & 63)) & 1ULL) sol.push_back(c + 1);
            }
        }
        cout << sol.size();
        for (int v : sol) cout << ' ' << v;
        cout << "\n";
    }
    return 0;
}
