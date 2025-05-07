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
    int n, c;
    cin >> n >> c;
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
    vector<array<int, 2>> dp(n + 1, {0, 0});
    auto dfs = [&] (auto &&self, int u, int p) -> void {
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(self, v, u);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += max(dp[v][0], dp[v][1] - 2 * c);
      }
      dp[u][1] += a[u];
    };
    dfs(dfs, 1, 1);
    cout << max({int(0), dp[1][0], dp[1][1]}) << '\n';
  }
}


