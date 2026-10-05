#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;
const int WORDS = (MAXN + 63) / 64;

struct Bitset {
    uint64_t w[WORDS];
    Bitset() { memset(w, 0, sizeof(w)); }
    bool get(int i) const { return (w[i >> 6] >> (i & 63)) & 1; }
    void set(int i) { w[i >> 6] |= 1ULL << (i & 63); }
    void flip(int i) { w[i >> 6] ^= 1ULL << (i & 63); }
    void xor_with(const Bitset& other) {
        for (int k = 0; k < WORDS; ++k) w[k] ^= other.w[k];
    }
    int count() const {
        int c = 0;
        for (int k = 0; k < WORDS; ++k) c += __builtin_popcountll(w[k]);
        return c;
    }
    int parity_with(const Bitset& other) const {
        int p = 0;
        for (int k = 0; k < WORDS; ++k) p ^= __builtin_parityll(w[k] & other.w[k]);
        return p;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<Bitset> A(N), P(N);
    for (int i = 0; i < N; ++i) {
        A[i].set(i);
        P[i].set(i);
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        A[u].set(v);
        A[v].set(u);
    }
    
    // Gaussian elimination to RREF
    vector<int> pivot_col(N, -1);
    vector<int> pivot_row(N, -1);
    
    int row = 0;
    for (int col = 0; col < N && row < N; ++col) {
        int sel = -1;
        for (int i = row; i < N; ++i) {
            if (A[i].get(col)) {
                sel = i;
                break;
            }
        }
        if (sel == -1) continue;
        
        swap(A[sel], A[row]);
        swap(P[sel], P[row]);
        
        for (int i = 0; i < N; ++i) {
            if (i != row && A[i].get(col)) {
                A[i].xor_with(A[row]);
                P[i].xor_with(P[row]);
            }
        }
        
        pivot_col[row] = col;
        pivot_row[col] = row;
        ++row;
    }
    
    int rank = row;
    
    // Process queries
    string line;
    Bitset b_bitset;
    for (int qq = 0; qq < Q; ++qq) {
        vector<int> b;
        while ((int)b.size() < N) {
            if (!getline(cin, line)) break;
            for (char c : line) {
                if (c == '0' || c == '1') {
                    b.push_back(c == '0' ? 1 : 0);
                }
            }
        }
        
        b_bitset = Bitset();
        for (int i = 0; i < N; ++i) {
            if (b[i]) b_bitset.set(i);
        }
        
        // Compute b' = P * b using bitset parity
        vector<int> bp(N);
        for (int i = 0; i < N; ++i) {
            bp[i] = P[i].parity_with(b_bitset);
        }
        
        // Check consistency
        bool ok = true;
        for (int i = rank; i < N; ++i) {
            if (bp[i]) { ok = false; break; }
        }
        
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        
        // Construct solution
        vector<int> x(N, 0);
        for (int col = 0; col < N; ++col) {
            if (pivot_row[col] != -1) {
                x[col] = bp[pivot_row[col]];
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < N; ++i) if (x[i]) ans.push_back(i + 1);
        cout << ans.size();
        for (int v : ans) cout << ' ' << v;
        cout << '\n';
    }
    return 0;
}