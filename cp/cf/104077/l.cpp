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
    for (int i = 2; i <= n; i++) {
      int v;
      cin >> v;
      adj[i].push_back(v);
      adj[v].push_back(i);
    }

    vector<int> h(n + 1, 1);
    vector<int> cnt(n + 1);
    auto dfs = [&](auto &&self, int u, int p) -> void {
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(self, v, u);
        h[u] = max(h[u], h[v] + 1);
      }
      cnt[h[u]] += 1;
    };

    dfs(dfs, 1, 1);
    dbg(h);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
      ans = min(ans, i + cnt[i] - 1);
    }
    cout << ans << '\n';
  }
}
