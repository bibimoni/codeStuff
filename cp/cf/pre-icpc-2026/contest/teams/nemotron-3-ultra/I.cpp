#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) : parent(n, -1), sz(n, 1) {}
    int find(int x) {
        if (parent[x] == -1) return -1;
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == -1 || b == -1) return false;
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
    void make_set(int x) {
        parent[x] = x;
        sz[x] = 1;
    }
    bool is_set(int x) const {
        return parent[x] != -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> g[i][j];
            }
        }
        int q;
        cin >> q;
        vector<pair<int,int>> destr(q);
        for (int i = 0; i < q; ++i) {
            int r, c;
            cin >> r >> c;
            --r; --c;
            destr[i] = {r, c};
        }
        
        int total_cells = n * m;
        vector<int> destroyed(total_cells, 0);
        for (auto [r, c] : destr) {
            destroyed[r * m + c] = 1;
        }
        
        DSU dsu(total_cells);
        long long V = 0, E = 0, C = 0;
        
        // Directions: up, right, down, left
        const int dr[4] = {-1, 0, 1, 0};
        const int dc[4] = {0, 1, 0, -1};
        const int bit[4] = {1, 2, 4, 8};
        const int opp_bit[4] = {4, 8, 1, 2}; // up<->down, right<->left
        
        // Build initial State q (all q destroyed)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int id = i * m + j;
                if (g[i][j] == 0) continue; // empty
                if (destroyed[id]) continue;
                
                V++;
                dsu.make_set(id);
                C++;
                
                // Check edges to already processed neighbors (up and left to avoid double counting)
                for (int d = 0; d < 2; ++d) { // up and left
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if (ni < 0 || nj < 0) continue;
                    int nid = ni * m + nj;
                    if (g[ni][nj] == 0) continue;
                    if (destroyed[nid]) continue;
                    // Check if both have openings
                    if ((g[i][j] & bit[d]) && (g[ni][nj] & opp_bit[d])) {
                        E++;
                        if (dsu.unite(id, nid)) C--;
                    }
                }
                // Also check down and right for already processed cells (they will be processed later in row-major)
                // Actually, we can just check all 4 directions and only process if neighbor id < current id
                // But simpler: do a second pass or check all 4 directions with id comparison
            }
        }
        
        // Second pass for remaining edges (down and right) - or better, do all 4 directions with id check
        // Let's redo: for each cell, check all 4 directions, only add edge if neighbor id < current id
        // But we already did up/left in first pass. Let's just do a separate loop for all edges.
        
        // Reset and do it cleanly
        dsu = DSU(total_cells);
        V = 0; E = 0; C = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int id = i * m + j;
                if (g[i][j] == 0) continue;
                if (destroyed[id]) continue;
                
                V++;
                dsu.make_set(id);
                C++;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int id = i * m + j;
                if (g[i][j] == 0) continue;
                if (destroyed[id]) continue;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    int nid = ni * m + nj;
                    if (g[ni][nj] == 0) continue;
                    if (destroyed[nid]) continue;
                    // Only add edge once: when nid < id
                    if (nid >= id) continue;
                    if ((g[i][j] & bit[d]) && (g[ni][nj] & opp_bit[d])) {
                        E++;
                        if (dsu.unite(id, nid)) C--;
                    }
                }
            }
        }
        
        vector<long long> ans(q);
        if (q > 0) {
            ans[q-1] = E - V + C;
        }
        
        // Process destructions in reverse
        for (int i = q - 1; i >= 1; --i) {
            int r = destr[i].first;
            int c = destr[i].second;
            int id = r * m + c;
            
            // Add this junction back
            destroyed[id] = 0;
            V++;
            dsu.make_set(id);
            C++;
            
            // Check all 4 neighbors for edges
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int nid = nr * m + nc;
                if (g[nr][nc] == 0) continue;
                if (destroyed[nid]) continue;
                if ((g[r][c] & bit[d]) && (g[nr][nc] & opp_bit[d])) {
                    E++;
                    if (dsu.unite(id, nid)) C--;
                }
            }
            
            ans[i-1] = E - V + C;
        }
        
        if (q == 0) {
            cout << '\n';
        } else {
            for (int i = 0; i < q; ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
    }
    return 0;
}