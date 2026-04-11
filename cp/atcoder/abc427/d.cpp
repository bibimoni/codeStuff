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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    queue<pair<int, int>> que;
    que.push({1, 0});
    while (que.size()) {
      auto [u, cnt] = que.front();
      for (auto v : adj[u]) {
        if (cnt + 1 > 2 * k) {
          continue;
        }
        que.push({v, cnt + 1});
      }
    }
  }
}
