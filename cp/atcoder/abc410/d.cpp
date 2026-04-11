/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  vector<vector<int>> dp(n + 1, vector<int>(1 << 10, 0));
  dp[1][0] = 1;
  auto dfs = [&](auto &&self, int u) -> void {
    for (auto [v, w] : adj[u]) {
      for (int j = 0; j < (1 << 10); j++) {
        if (!dp[u][j]) {
          continue;
        }
        if (dp[v][j ^ w]) {
          continue;
        }
        dp[v][j ^ w] = 1;
        self(self, v);
      }
    }
  };
  dfs(dfs, 1);
  int ans = -1;
  for (int j = 0; j < (1 << 10); j++) {
    if (dp[n][j]) {
      ans = j;
      break;
    }
  }
  cout << ans << '\n';
}
