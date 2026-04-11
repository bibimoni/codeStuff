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
    vector<int> deg(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      if (x > y) {
        swap(u, v);
      }
      adj[u].push_back(v);
      deg[v] += 1;
    }

    queue<int> que;
    for (int i = 1; i <= n; i++) {
      if (deg[i] == 0) {
        que.push(i);
      }
    }

    vector<int> ans(n);
    int ord = 1;
    while (que.size()) {
      int u = que.front();
      que.pop();
      ans[u - 1] = ord;
      ord += 1;
      for (int v : adj[u]) {
        deg[v] -= 1;
        if (deg[v] == 0) {
          que.push(v);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
}
