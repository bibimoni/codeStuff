#include <bits/stdc++.h>
using namespace std;

const int MAXC = 3500;
const int WORDS = (MAXC + 63) / 64; // 55

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
        // A[i][i] = 1
        mat[i][i >> 6] |= (1ULL << (i & 63));
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        mat[u][v >> 6] |= (1ULL << (v & 63));
        mat[v][u >> 6] |= (1ULL << (u & 63));
    }
    
    // Read queries, set RHS columns (N to N+Q-1)
    for (int q = 0; q < Q; ++q) {
        string s;
        for (int i = 0; i < N; ++i) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        for (int i = 0; i < N; ++i) {
            // b[i] = 1 - initial[i] = (s[i] == '0')
            if (s[i] == '0') {
                int col = N + q;
                mat[i][col >> 6] |= (1ULL << (col & 63));
            }
        }
    }
    
    // Gaussian elimination to RREF on first N columns
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
        
        // eliminate from all other rows
        for (int i = 0; i < N; ++i) {
            if (i != row && (mat[i][col >> 6] & (1ULL << (col & 63)))) {
                for (int w = 0; w < W; ++w) {
                    mat[i][w] ^= mat[row][w];
                }
            }
        }
        row++;
    }
    
    // Process each query
    for (int q = 0; q < Q; ++q) {
        int rhs_col = N + q;
        bool ok = true;
        // Check rows from rank to N-1 (all-zero in A part)
        for (int i = row; i < N; ++i) {
            if (mat[i][rhs_col >> 6] & (1ULL << (rhs_col & 63))) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        
        vector<int> ans;
        for (int col = 0; col < N; ++col) {
            if (where[col] != -1) {
                int r = where[col];
                if (mat[r][rhs_col >> 6] & (1ULL << (rhs_col & 63))) {
                    ans.push_back(col + 1);
                }
            }
        }
        cout << ans.size();
        for (int x : ans) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}