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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n + 1), y(n + 1);
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    adj[x[i]].push_back({y[i], i});
  }
  dbg(adj);

  for (int u = 0; u <= n; u++) {
    sort(adj[u].begin(), adj[u].end());
  }

  vector<int> p(n + 1);
  int ord = 0;
  auto dfs = [&](auto &&self, int u) -> void {
    p[ord] = u;
    ord += 1;
    for (auto [_, v] : adj[u]) {
      self(self, v);
    }
  };

  dfs(dfs, 0);

  for (int i = 1; i <= n; i++) {
    cout << p[i] << " \n"[i == n];
  }
}
