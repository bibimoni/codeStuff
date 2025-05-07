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
#define int            long long


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> h(n + 1, 0), parent(n + 1, -1);
    vector<int> path;
    auto dfs = [&] (auto &&self, int u, int p = -1) -> void {
      for(int v : adj[u]) {
        if(v == p)
          continue;
        h[v] = h[u] + 1;
        parent[v] = u;
        self(self, v, u);
      }
    };
    dfs(dfs, b);
    int ans = ceil(h[a] / 2.0);
    int mid = a;
    for(int i = 0; i < h[a] / 2; i++) {
      mid = parent[mid];
    }
    h = vector<int>(n + 1, 0);
    dfs(dfs, mid);
    cout << ans + 2 * (n - 1) - *max_element(h.begin(), h.end()) << '\n';
  }
}


