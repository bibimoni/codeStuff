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
    int n, k;
    cin >> n >> k;
    vector<int> mark(n + 1);
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      mark[x] = 1;
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (k == 1) {
      cout << "0\n";
      continue;
    }
    int curr = 0, ver = 1;
    auto dfs = [&] (auto &&self, int d, int u, int p = -1) -> void {
      if (mark[u]) {
        if (curr < d) {
          curr = d; 
          ver = u;
        }
      }
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(self, d + 1, v, u);
      }
    };  
    dfs(dfs, 0, 1);
    curr = 0;
    dfs(dfs, 0, ver);
    cout << (curr + 1) / 2 << '\n';
  }
}

