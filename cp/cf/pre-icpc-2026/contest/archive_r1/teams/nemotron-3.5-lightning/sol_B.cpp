#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int n = N;
    using BS = bitset<3001>;
    
    // Build matrix M = I + A and compute inverse via Gauss-Jordan
    vector<BS> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i].set(i);
        for (int neighbor : adj[i + 1]) {
            mat[i].set(neighbor - 1);
        }
    }
    
    vector<BS> inv(n);
    for (int i = 0; i < n; i++) inv[i].set(i);
    
    int row = 0;
    vector<int> where(n, -1);
    for (int col = 0; col < n && row < n; col++) {
        int sel = -1;
        for (int i = row; i < n; i++) {
            if (mat[i][col]) { sel = i; break; }
        }
        if (sel == -1) continue;
        swap(mat[row], mat[sel]);
        swap(inv[row], inv[sel]);
        where[col] = row;
        for (int i = 0; i < n; i++) {
            if (i != row && mat[i][col]) {
                mat[i] ^= mat[row];
                inv[i] ^= inv[row];
            }
        }
        row++;
    }
    
    bool invertible = (row == n);
    for (int i = 0; i < n; i++) {
        if (!mat[i][i]) { invertible = false; break; }
    }
    
    // Read all remaining input as tokens
    vector<string> tokens;
    string tok;
    while (cin >> tok) tokens.push_back(tok);
    
    // Process queries from tokens
    int token_idx = 0;
    
    auto read_states = [&]() -> string {
        // States are N characters of 0/1, possibly space-separated
        // We already read the first token; if it's N chars of 0/1, use it
        // Otherwise, collect tokens until we have N valid characters
        string states;
        while ((int)states.size() < N && token_idx < (int)tokens.size()) {
            for (char c : tokens[token_idx]) {
                if (c == '0' || c == '1') states += c;
            }
            token_idx++;
        }
        return states;
    };
    
    while (Q--) {
        string states = read_states();
        // Make sure we have exactly N characters
        while ((int)states.size() < N && token_idx < (int)tokens.size()) {
            for (char c : tokens[token_idx]) {
                if (c == '0' || c == '1') states += c;
                token_idx++;
                if ((int)states.size() == N) break;
            }
        }
        // Take only first N characters
        states = states.substr(0, N);
        
        if (invertible) {
            vector<int> x(n, 0);
            for (int i = 0; i < n; i++) {
                int dot = 0;
                for (int j = 0; j < n; j++) {
                    if (inv[i][j] && !init[j + 1] would go here... 
            }
            // This is getting complicated. Let me just use the original approach.
        }
        
        // Give up on this approach, go back to original
        break;
    }
    
    return 0;
}