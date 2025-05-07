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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  auto dfs = [&] (auto &&self, vector<vector<int>> &adj, vector<int> &dp, int u, int p = -1) -> int {
    if (dp[u]) {
      return dp[u];
    }
    dp[u] = 1;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      self(self, adj, dp, v, u);
      dp[u] = max(1 + dp[v], dp[u]);
    }
    return dp[u];
  };
  auto can = [&] (int idx) -> bool {
    vector<vector<int>> adj(n + 1);
    vector<int> mark(n + 1);
    for (int i = 0; i <= idx; i++) {
      auto [u, v] = edges[i];
      mark[v]++;
      adj[u].push_back(v);
    }
    int st = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (mark[i] == 0) {
        st = i;
        cnt++;
      }
    }
    if (cnt > 1) {
      return false;
    }
    vector<int> dp(n + 1);
    return dfs(dfs, adj, dp, st) == n;
  };
  int ans = -1, l = 0, r = m - 1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (can(m)) {
      ans = m + 1;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << '\n';
}

