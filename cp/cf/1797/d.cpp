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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<set<pair<int, int>>> sz(n + 1);
  vector<int> importance(n + 1), p(n + 1, -1);
  vector<int> siz(n + 1);
  auto dfs = [&] (auto&& self, int u) -> void {
    importance[u] = a[u];
    siz[u] = 1;
    for (int v : adj[u]) {
      if (v == p[u]) {
        continue;
      }
      p[v] = u;
      self(self, v);
      siz[u] += siz[v];
      sz[u].insert({-siz[v], v});
      importance[u] += importance[v];
    }
  };

  dfs(dfs, 1);

  while (m--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      cout << importance[x] << '\n';
    } else {
      if (!sz[x].size()) {
        continue;
      }
      auto son = sz[x].begin()->second;
      sz[p[x]].erase({-siz[x], x});
      sz[x].erase({-siz[son], son});

      siz[x] -= siz[son];
      siz[son] += siz[x];
      importance[x] -= importance[son];
      importance[son] += importance[x];
      
      sz[son].insert({-siz[x], x});
      sz[p[x]].insert({-siz[son], son});x

      p[son] = p[x];
      p[x] = son;
      
    }
  }
}

