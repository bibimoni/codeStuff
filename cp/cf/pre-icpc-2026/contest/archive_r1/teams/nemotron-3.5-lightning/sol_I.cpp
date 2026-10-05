#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    // Direction vectors and opening bit values
    // 1=up, 2=right, 4=down, 8=left
    // Two adjacent cells are connected if both have facing openings
    
    auto has_connection = [&](int val1, int val2, int dir) -> bool {
        // dir: 0=up, 1=right, 2=down, 3=left
        if (dir == 0) { // up: val1 has up, val2 has down
            return (val1 & 1) && (val2 & 4);
        } else if (dir == 1) { // right: val1 has right, val2 has left
            return (val1 & 2) && (val2 & 8);
        } else if (dir == 2) { // down: val1 has down, val2 has up
            return (val1 & 4) && (val2 & 1);
        } else { // left: val1 has left, val2 has right
            return (val1 & 8) && (val2 & 2);
        }
    };
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> g(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        
        int q;
        cin >> q;
        
        vector<pair<int, int>> impacts(q);
        for (int i = 0; i < q; i++) {
            int r, c;
            cin >> r >> c;
            impacts[i] = {r - 1, c - 1};
        }
        
        vector<vector<bool>> active(n, vector<bool>(m, true));
        
        auto compute_loops = [&]() -> int {
            int V = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (active[i][j]) V++;
                }
            }
            
            if (V == 0) return 0;
            
            int E = 0;
            // Count edges: for each active cell, check right and down neighbors
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!active[i][j]) continue;
                    
                    // Check right
                    if (j + 1 < m && active[i][j+1]) {
                        if (has_connection(g[i][j], g[i][j+1], 1)) {
                            E++;
                        }
                    }
                    
                    // Check down
                    if (i + 1 < n && active[i+1][j]) {
                        if (has_connection(g[i][j], g[i+1][j], 2)) {
                            E++;
                        }
                    }
                }
            }
            
            // Count connected components using DSU
            vector<int> parent(n * m);
            iota(parent.begin(), parent.end(), 0);
            
            function<int(int)> find = [&](int x) -> int {
                return parent[x] == x ? x : parent[x] = find(parent[x]);
            };
            
            auto unite = [&](int x, int y) {
                int px = find(x), py = find(y);
                if (px != py) parent[px] = py;
            };
            
            // Map 2D to 1D
            auto idx = [&](int i, int j) { return i * m + j; };
            
            // Union connected components
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!active[i][j]) continue;
                    
                    // Union with right neighbor if connected
                    if (j + 1 < m && active[i][j+1] && has_connection(g[i][j], g[i][j+1], 1)) {
                        unite(idx(i, j), idx(i, j+1));
                    }
                    // Union with down neighbor if connected
                    if (i + 1 < n && active[i+1][j] && has_connection(g[i][j], g[i+1][j], 2)) {
                        unite(idx(i, j), idx(i+1, j));
                    }
                }
            }
            
            // Count unique roots
            set<int> roots;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (active[i][j]) {
                        roots.insert(find(idx(i, j)));
                    }
                }
            }
            
            int C = roots.size();
            return E - V + C;
        };
        
        vector<int> results;
        for (int i = 0; i < q; i++) {
            auto [r, c] = impacts[i];
            active[r][c] = false;
            int loops = compute_loops();
            results.push_back(loops);
        }
        
        for (int i = 0; i < (int)results.size(); i++) {
            if (i > 0) cout << " ";
            cout << results[i];
        }
        cout << "\n";
    }
    
    return 0;
}
