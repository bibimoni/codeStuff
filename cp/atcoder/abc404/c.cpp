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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n != m) {
    cout << "No";
    return 0;
  }
  
  vector<int> was(n + 1, 0);
  vector<int> nodes;
  auto dfs = [&] (auto && self, int u, int p) -> void {
    nodes.push_back(u);
    was[u] = 1;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      if (was[v]) {
        continue;
      }
      self(self, v, u);
    }
  };
  dfs(dfs, 1, 1);
  bool ok = false;
  for (auto v : adj[nodes.back()]) {
    ok |= v == 1;
  }
  if (nodes.size() == n && ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}


