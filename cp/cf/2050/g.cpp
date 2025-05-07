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
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> h(n + 1, 0);
    vector<int> trace(n + 1, -1);
    auto dfs = [&] (this auto &&self, int u, int p) -> void {
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        trace[v] = u;
        h[v] = h[u] + 1;
        self(v, u);
      }
    };
    dfs(1, 1);
    int u1 = max_element(h.begin(), h.end()) - h.begin();
    h = vector<int>(n + 1, 0);
    trace = vector<int>(n + 1, -1);
    dfs(u1, u1);
    int u2 = max_element(h.begin(), h.end()) - h.begin();
    int cur = u2;
    vector<int> path;
    while (cur != u1) {
      path.push_back(cur);
      cur = trace[cur];
    }    
    path.push_back(u1);
    dbg(path);
  }
}

