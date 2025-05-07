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
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> deg(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u] += 1;
    deg[v] += 1;
  }
  int ans = 1e9;
  for (int u = 1; u <= n; u++) {
    sort(adj[u].begin(), adj[u].end(), [&] (int i, int j) {
      return deg[i] > deg[j];
    });
    int x = 0, y = 0;
    for (int v : adj[u]) {
      x += 1;
      y = deg[v] - 1;
      ans = min(ans, n - (1 + x + x * y));
    }
  }
  cout << ans;
}


