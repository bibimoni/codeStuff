#include <bits/stdc++.h>
using namespace std;

const int MAXC = 3500;
const int WORDS = (MAXC + 63) / 64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    int COLS = N + Q;
    int W = (COLS + 63) / 64;
    
    vector<array<uint64_t, WORDS>> mat(N);
    for (int i = 0; i < N; ++i) {
        for (int w = 0; w < WORDS; ++w) mat[i][w] = 0;
        mat[i][i >> 6] |= (1ULL << (i & 63));
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        mat[u][v >> 6] |= (1ULL << (v & 63));
        mat[v][u >> 6] |= (1ULL << (u & 63));
    }
    
    vector<string> queries(Q);
    for (int q = 0; q < Q; ++q) {
        cin >> queries[q];
        for (int i = 0; i < N; ++i) {
            if (queries[q][i] == '0') {
                int col = N + q;
                mat[i][col >> 6] |= (1ULL << (col & 63));
            }
        }
    }
    
    // Print initial matrix for debug
    cerr << "Initial matrix (first 7 cols + 5 RHS):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N + Q; ++j) {
            cerr << ((mat[i][j >> 6] & (1ULL << (j & 63))) ? '1' : '0') << ' ';
        }
        cerr << '\n';
    }
    
    vector<int> where(N, -1);
    int row = 0;
    for (int col = 0; col < N && row < N; ++col) {
        int sel = -1;
        for (int i = row; i < N; ++i) {
            if (mat[i][col >> 6] & (1ULL << (col & 63))) {
                sel = i;
                break;
            }
        }
        if (sel == -1) continue;
        swap(mat[sel], mat[row]);
        where[col] = row;
        
        for (int i = 0; i < N; ++i) {
            if (i != row && (mat[i][col >> 6] & (1ULL << (col & 63)))) {
                for (int w = 0; w < W; ++w) {
                    mat[i][w] ^= mat[row][w];
                }
            }
        }
        row++;
    }
    
    cerr << "\nAfter elimination:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N + Q; ++j) {
            cerr << ((mat[i][j >> 6] & (1ULL << (j & 63))) ? '1' : '0') << ' ';
        }
        cerr << '\n';
    }
    
    cerr << "\nwhere: ";
    for (int i = 0; i < N; ++i) cerr << where[i] << ' ';
    cerr << "\nrank: " << row << '\n';
    
    return 0;
}
