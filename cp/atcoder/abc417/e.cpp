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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
      sort(adj[u].begin(), adj[u].end());
    }

    vector<int> was(n + 1);
    vector<int> ans;
    vector<int> ret;
    bool ok = false;
    auto dfs = [&](auto &&self, int u, int p) -> void {
      if (was[u] == 1) {
        return;
      }
      was[u] = 1;
      if (!ok) {
        ans.push_back(u);
      }
      if (u == y) {
        if (!ok) {
          ret = ans;
        }
        ok = true;
        return;
      }

      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(self, v, u);
      }

      ans.pop_back();
    };

    dfs(dfs, x, x);
    for (int v : ret) {
      cout << v << ' ';
    }
    cout << '\n';
  }
}
