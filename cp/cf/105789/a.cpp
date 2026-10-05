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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, char>>> g(n);
  vector<vector<pair<int, char>>> h(n);
  queue<pair<int, int>> que;
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    u -= 1;
    v -= 1;
    g[u].push_back({v, c});
    h[v].push_back({u, c});
    dbg("push", u, v, c);
    que.push({u, v});
  }

  for (int i = 0; i < n; i++) {
    que.push({i, i});
  }

  vector was(n, vector<int>(n));
  int ans = 0;
  while (que.size()) {
    auto [u, v] = que.front();
    dbg("que", u, v);
    que.pop();
    if (was[u][v]) {
      continue;
    }
    was[u][v] = 1;

    if (u != v) {
      dbg(u, v);
      ans += 1;
    }

    for (auto [nv, cv] : g[v]) {
      for (auto [nu, cu] : h[u]) {
        if (cu != cv) {
          continue;
        }
        que.push({nu, nv});
      }
    }
  }

  cout << ans << '\n';
}
