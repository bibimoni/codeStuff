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
  int n;
  cin >> n;
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> cur(n + 1);
  vector<int> val(n + 1);
  auto dfs1 = [&](auto &&self, int u, int p) -> void {
    cur[u] = x[u];
    for (auto [v, w] : adj[u]) {
      if (v == p) {
        continue;
      }

      self(self, v, u);
      val[u] += val[v] + w * abs(cur[v]);
      cur[u] += cur[v];
    }
  };

  dfs1(dfs1, 1, 1);
  // const int INF = 1e18;
  // int ans = INF;
  // auto dfs = [&](auto &&self, int u, int p) -> void {
  //   ans = min(ans, val[u]);
  //   // dbg(u, val[u]);
  //   for (auto [v, w] : adj[u]) {
  //     if (v == p) {
  //       continue;
  //     }
  //
  //     int old_cur_u = cur[u];
  //     int old_cur_v = cur[v];
  //     int old_val_u = val[u];
  //     int old_val_v = val[v];
  //     cur[u] = old_cur_u - old_cur_v;
  //     val[u] = old_val_u - w * abs(old_cur_v) - old_val_v;
  //     cur[v] = old_cur_v + cur[u];
  //     val[v] = old_val_v + w * abs(cur[u]) + val[u];
  //
  //     // dbg(v, cur[v], val[v], old_cur_v, old_val_v);
  //     self(self, v, u);
  //
  //     cur[u] = old_cur_u;
  //     cur[v] = old_cur_v;
  //     val[u] = old_val_u;
  //     val[v] = old_val_v;
  //   }
  // };
  //
  // dfs(dfs, 1, 1);
  cout << val[1] << '\n';
}
