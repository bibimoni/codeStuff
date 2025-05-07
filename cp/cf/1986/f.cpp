// time-limit: 3000
/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> num(n + 1, 0), low(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int ans = n * (n - 1) / 2;
    int timeDfs = 0;
    vector<int> sz(n + 1, 1);
    auto dfs = [&](auto &&self, int u, int p = -1) -> void {
      low[u] = num[u] = ++timeDfs;
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        if (!num[v]) {
          self(self, v, u);
          low[u] = min(low[u], low[v]);
          sz[u] += sz[v];
          if (low[v] == num[v]) {
            int szv = sz[v], szu = n - sz[v];
            ans = min(ans, n * (n - 1) / 2 - szu * szv);
          }
        } else {
          low[u] = min(low[u], low[v]);          
        }
      }
    };
    dfs(dfs, 1, 1);
    cout << ans << '\n';
  }
}


