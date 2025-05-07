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
  // freopen("DICHUYEN.inp", "r", stdin);
  // freopen("DICHUYEN.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  map<pair<int, int>, int> edges;
  for (int i = 0; i < m; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    if (!edges.count({u, v})) {
      edges[{u, v}] = t;
    } else {
      edges[{u, v}] = min(edges[{u, v}], t);
    }
  }
  m = edges.size();
  vector<vector<pair<int, int>>> adj(n + 1);
  vector<vector<int>> come(n + 1);
  for (int u = 1; u <= n; u++) {
    come[u].push_back(u);
  }
  for (const auto &[p, t] : edges) {
    adj[p.first].push_back({p.second, t});
    come[p.second].push_back(p.first);
  }
  int k, q;
  cin >> k >> q;
  const int INF = 1e9;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
  // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2 * n * m + 1, INF)));
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0;
  }
  for (int step = 1; step <= min(2 * n * m, k); step++) {
    vector<vector<int>> ndp(n + 1, vector<int>(m + 1, INF));    
  
    for (int u = 1; u <= n; u++) {
      for (int v : come[u]) {
        for (auto [x, t] : adj[u]) {
          ndp[v][x] = min(ndp[v][x], dp[v][u] + t);
        }
      }
    }
    swap(ndp, dp);
  }
  // for (int step = 1; step <= min(2 * n * m, k); step++) {
  //   for (int u = 1; u <= n; u++) {
  //     for (int v = 1; v <= n; v++) {
  //       dp[u][v][step] = min(dp[u][v][step], dp[u][v][step - 1]);
  //     }
  //   }
  // }
  while (q--) {
    int c, d;
    cin >> c >> d;
    if (c == d) {
      cout << 0 << '\n';
      continue;
    }
    int ans = dp[c][d];
    cout << (ans == INF ? -1 : ans) << '\n';
  }
} 


