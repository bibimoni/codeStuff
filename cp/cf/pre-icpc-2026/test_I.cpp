#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 4;
    while (t--) {
        int n = 2, m = 3;
        vector<vector<int>> g = {{15, 15, 15}, {15, 15, 15}};
        int q = 3;
        vector<pair<int,int>> impacts = {{1,1}, {1,2}, {2,2}};
        
        vector<vector<bool>> active(n, vector<bool>(m, true));
        
        for (int i = 0; i < q; i++) {
            int r = impacts[i].first, c = impacts[i].second;
            active[r-1][c-1] = false;
            
            int V = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (active[i][j]) V++;
                }
            }
            cout << "After impact " << i+1 << ": V=" << V << "\n";
            
            // Count edges
            int E = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!active[i][j]) continue;
                    if (j + 1 < m && active[i][j+1]) {
                        if ((g[i][j] & 2) && (g[i][j+1] & 8)) E++;
                    }
                    if (i + 1 < n && active[i+1][j]) {
                        if ((g[i][j] & 4) && (g[i+1][j] & 1)) E++;
                    }
                }
            }
            cout << "E=" << E << "\n";
            
            // DSU
            vector<int> parent(n * m);
            iota(parent.begin(), parent.end(), 0);
            function<int(int)> find = [&](int x) -> int {
                return parent[x] == x ? x : parent[x] = find(parent[x]);
            };
            auto unite = [&](int x, int y) {
                int px = find(x), py = find(y);
                if (px != py) parent[px] = py;
            };
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!active[i][j]) continue;
                    if (j + 1 < m && active[i][j+1] && ((g[i][j] & 2) && (g[i][j+1] & 8))) {
                        unite(i * m + j, i * m + j + 1);
                    }
                    if (i + 1 < n && active[i+1][j] && ((g[i][j] & 4) && (g[i+1][j] & 1))) {
                        unite(i * m + j, (i+1) * m + j);
                    }
                }
            }
            
            set<int> roots;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (active[i][j]) roots.insert(find(i * m + j));
                }
            }
            int C = roots.size();
            cout << "C=" << C << " loops=" << E - V + C << "\n";
        }
    }
    return 0;
}
