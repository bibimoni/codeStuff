#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rnk;
    DSU(int n) : parent(n), rnk(n, 0) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        
        vector<vector<int>> g(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &g[i][j]);
        
        int q;
        scanf("%d", &q);
        vector<pair<int,int>> del(q);
        
        for (int i = 0; i < q; i++) {
            int r, c;
            scanf("%d%d", &r, &c);
            r--; c--;
            del[i] = {r, c};
        }
        
        auto idx = [&](int r, int c) -> int { return r * m + c; };
        auto is_junction = [&](int r, int c) -> bool { return g[r][c] != 0; };
        
        auto connected = [&](int r1, int c1, int r2, int c2) -> bool {
            if (!is_junction(r1, c1) || !is_junction(r2, c2)) return false;
            int v1 = g[r1][c1], v2 = g[r2][c2];
            if (r2 == r1 + 1) return (v1 & 4) && (v2 & 1);
            if (r2 == r1 - 1) return (v1 & 1) && (v2 & 4);
            if (c2 == c1 + 1) return (v1 & 2) && (v2 & 8);
            if (c2 == c1 - 1) return (v1 & 8) && (v2 & 2);
            return false;
        };
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        DSU dsu(n * m);
        vector<bool> active(n * m, false);
        vector<int> ans(q);
        
        // Mark deleted nodes
        vector<bool> is_deleted(n * m, false);
        for (int i = 0; i < q; i++) {
            is_deleted[idx(del[i].first, del[i].second)] = true;
        }
        
        // Activate all non-deleted junctions
        int V = 0, E = 0, C = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (is_junction(r, c) && !is_deleted[idx(r, c)]) {
                    active[idx(r, c)] = true;
                    V++;
                    C++;
                }
            }
        }
        
        // Build initial edges among active nodes
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (!active[idx(r, c)]) continue;
                int v = idx(r, c);
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (!active[idx(nr, nc)]) continue;
                    if (nr * m + nc > v && connected(r, c, nr, nc)) {
                        E++;
                        if (dsu.unite(v, idx(nr, nc))) {
                            C--;
                        }
                    }
                }
            }
        }
        
        // Process deletions in reverse: start from S_q, add back d_{q-1}, d_{q-2}, ..., d_0
        // After adding d_i, we get S_i with cycle rank r_i = ans[i-1] (for i > 0)
        // ans[q-1] = r_q from initial state
        
        if (q > 0) {
            ans[q - 1] = E - V + C;
        }
        
        for (int i = q - 1; i >= 1; i--) {
            auto [r, c] = del[i];
            int v = idx(r, c);
            
            active[v] = true;
            V++;
            C++;
            
            int deg = 0;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (!active[idx(nr, nc)]) continue;
                if (connected(r, c, nr, nc)) {
                    deg++;
                    if (dsu.unite(v, idx(nr, nc))) {
                        C--;
                    }
                }
            }
            
            E += deg;
            ans[i - 1] = E - V + C;
        }
        
        for (int i = 0; i < q; i++) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
