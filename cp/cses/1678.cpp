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
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    adj[u].push_back(v);
  }

  vector<int> was(n), trace(n, -1);
  int st = -1, ed = -1;
  auto dfs = [&](auto &&self, int u) -> bool {
    dbg(u, adj[u]);
    was[u] = 1;
    for (int v : adj[u]) {
      if (was[v] == 0) {
        trace[u] = v;
        if (self(self, v)) {
          return true;
        }
      } else if (was[v] == 1) {
        st = u;
        ed = v;
        return true;
      }
    }
    was[u] = 2;
    return false;
  };

  for (int i = 0; i < n; i++) {
    if (st == -1 && was[i] == 0) {
      dfs(dfs, i);
      // dbg(st);
    }
  }

  if (st == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<int> ans{st};
    for (int v = ed; v != st; v = trace[v]) {
      ans.push_back(v);
    }
    ans.push_back(st);

    cout << ans.size() << "\n";
    for (int i : ans) {
      cout << i + 1 << ' ';
    }
  }
}
