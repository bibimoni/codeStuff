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
// #define int int64_t
void solve() {
  int n; cin >> n;
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> dp(n + 1, 0);
  auto dfs = [&](auto self, int u, int par) -> void {
    if(adj[u].size() >= 2 && u == 1) dp[u] = 1;
    if(adj[u].size() > 2 && u != 1) dp[u] = 1;
    int mx = 0;
    for(auto v : adj[u]) {
      if(v == par) continue;
      self(self, v, u);
      mx = max(mx, dp[v]);
    }
    if(u == 1) {
      if(adj[u].size() >= 3) dp[u] = max(dp[u], mx + 1);
    }
    else {
      if(adj[u].size() >= 4) dp[u] = max(dp[u], mx + 1);
    }
  };  
  dfs(dfs, 1, 0);
  int ans = 0;
  auto reroot = [&](auto self, int u, int par) -> void {
    ans = max(ans, dp[u]);
    
  };
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1; cin >> tc;
  while(tc--) solve();
}
