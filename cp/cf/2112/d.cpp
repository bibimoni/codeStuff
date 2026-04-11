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
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      edges.push_back({u, v});
    }
    vector<int> nodes;
    for (int u = 1; u <= n; u++) {
      if (nodes.size()) {
        break;
      }
      for (int v : adj[u]) {
        if (adj[v].size() == 2) {
          nodes.push_back(u);
          nodes.push_back(v);
          nodes.push_back(adj[v][0] == u ? adj[v][1] : adj[v][0]);
          break;
        }
      }
    }
    if (nodes.size() == 0) {
      cout << "NO\n";
      continue;
    }
    map<pair<int, int>, int> was;
    map<pair<int, int>, pair<int, int>> ord;
    dbg(nodes);
    was[{nodes[0], nodes[1]}] = 1;
    was[{nodes[1], nodes[0]}] = 1;
    was[{nodes[2], nodes[1]}] = 1;
    was[{nodes[1], nodes[2]}] = 1;
    ord[{nodes[0], nodes[1]}] = {nodes[0], nodes[1]};
    ord[{nodes[1], nodes[0]}] = {nodes[0], nodes[1]};
    ord[{nodes[2], nodes[1]}] = {nodes[1], nodes[2]};
    ord[{nodes[1], nodes[2]}] = {nodes[1], nodes[2]};

    vector<int> d(n + 1, 0);
    auto dfs_path = [&](auto &&self, int u, int p, int rem) -> void {
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        if (was[{u, v}]) {
          continue;
        }
        was[{u, v}] = 1;
        was[{v, u}] = 1;
        if (d[u] % 2 == rem) {
          ord[{u, v}] = {v, u};
          ord[{v, u}] = {v, u};
        } else {
          ord[{u, v}] = {u, v};
          ord[{v, u}] = {u, v};
        }
        d[v] = d[u] + 1;
        self(self, v, u, rem);
      }
    };
    dfs_path(dfs_path, nodes[2], nodes[2], 0);
    dfs_path(dfs_path, nodes[0], nodes[0], 1);
    cout << "YES\n";
    for (auto [ux, vx] : edges) {
      auto [u, v] = ord[{ux, vx}];
      cout << u << ' ' << v << '\n';
    }
  }
}
