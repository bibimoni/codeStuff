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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
      adj[i].push_back(i - 1);
      adj[i - 1].push_back(i);
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    const int INF = int(1e9);
    vector<int> d(n + 1, INF);
    d[1] = 0;
    for (int i = 1; i <= n; i++) {
      for (int v : adj[i]) {
        if (v >= i) {
          continue;
        }
        d[i] = min(d[i], d[v] + 1);
      }
    }
    vector<int> ans(n, 1);
    vector<int> dp(n + 1);
    dp[1] = 0;
    ans[1] = 1;
    for (int i = 2; i < n; i++) {
      if (dp[i - 1] > 0) {
        dp[i - 1] -= 1;
      }
      for (int v : adj[i - 1]) {
        if (v <= i - 1) {
          continue;
        }
        // v - i - 1 - d[i - 1] > 0 -> Elsie wins
        dp[i] = max(dp[i - 1], v - i - 1 - d[i - 1]);
      }
      if (dp[i] > 0) {
        ans[i] = 0;
      }
    }
    for (int i = 1; i < n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  } 
}


