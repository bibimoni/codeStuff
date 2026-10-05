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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  set<int> ans;

  auto dfs = [&](auto &&self, int u) -> void {
    if (ans.count(u)) {
      return;
    }
    ans.insert(u);
    for (int v : adj[u]) {
      self(self, v);
    }
  };
  dfs(dfs, 1);

  cout << ans.size() << '\n';
}
