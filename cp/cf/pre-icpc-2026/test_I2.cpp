#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Second test case from problem
    int n = 1, m = 5;
    vector<vector<int>> g = {{6, 10, 12, 6, 12}};
    int q = 6;
    vector<pair<int,int>> impacts = {{2,2}, {1,2}, {2,5}, {1,5}, {3,1}, {2,4}};
    
    int V = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != 0) V++;
        }
    }
    cout << "Initial V=" << V << "\n";
    
    vector<vector<bool>> active(n, vector<bool>(m, true));
    
    for (int idx = 0; idx < q; idx++) {
        int r = impacts[idx].first, c = impacts[idx].second;
        active[r-1][c-1] = false;
        
        int Vcur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (active[i][j] && g[i][j] != 0) Vcur++;
            }
        }
        cout << "After impact " << idx+1 << ": V=" << Vcur << "\n";
        
        // Count edges
        int E = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!active[i][j] || g[i][j] == 0) continue;
                if (j + 1 < m && active[i][j+1] && g[i][j+1] != 0) {
                    if ((g[i][j] & 2) && (g[i][j+1] & 8)) E++;
                }
                if (i + 1 < n && active[i+1][j] && g[i+1][j] != 0) {
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
                if (!active[i][j] || g[i][j] == 0) continue;
                if (j + 1 < m && active[i][j+1] && g[i][j+1] != 0 && ((g[i][j] & 2) && (g[i][j+1] & 8))) {
                    unite(i * m + j, i * m + j + 1);
                }
                if (i + 1 < n && active[i+1][j] && g[i+1][j] != 0 && ((g[i][j] & 4) && (g[i+1][j] & 1))) {
                    unite(i * m + j, (i+1) * m + j);
                }
            }
        }
        
        set<int> roots;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (active[i][j] && g[i][j] != 0) roots.insert(find(i * m + j));
            }
        }
        int C = roots.size();
        cout << "C=" << C << " loops=" << E - Vcur + C << "\n";
    }
    return 0;
}
