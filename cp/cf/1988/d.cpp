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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    const int MX = 20, INF = int(1e18);
    vector<vector<int>> dp(n + 1, vector<int>(MX + 1, INF));
    auto dfs = [&] (auto &&self, int u, int p = -1) -> void {
      for (int i = 1; i < MX; i++) {
        dp[u][i] = a[u] * i;
      }
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(self, v, u);
        for (int i = 1; i < MX; i++) {
          int mn = INF;
          for (int j = 1; j < MX; j++) {
            if (i != j) {
              mn = min(mn, dp[v][j]);
            }
          }
          dp[u][i] += mn;
        }
      }
    };
    dfs(dfs, 1);
    cout << *min_element(dp[1].begin(), dp[1].end()) << '\n';
  }
}


