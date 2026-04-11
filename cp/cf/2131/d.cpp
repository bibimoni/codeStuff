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
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      deg[u] += 1;
      deg[v] += 1;
    }

    int leaves = 0;
    for (int u = 1; u <= n; u++) {
      leaves += int(deg[u] == 1);
    }

    int ans = 0;
    for (int u = 1; u <= n; u++) {
      int cur = int(deg[u] == 1);
      for (int v : adj[u]) {
        if (deg[v] == 1) {
          cur += 1;
        }
      }
      ans = max(ans, cur);
    }

    ans = leaves - ans;
    cout << ans << '\n';
  }
}
