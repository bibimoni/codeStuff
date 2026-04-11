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
    int n, m;
    cin >> n >> m;
    bool has_1 = false;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, -w});
      if (u == 1 || v == 1) {
        has_1 = true;
      }
    }

    if (!has_1) {
      cout << "0";
      for (int i = 0; i < n - 1; i++) {
        cout << " ?";
      }
      cout << '\n';
      continue;
    }

    vector<int> ans(n + 1, 0);
    vector<int> was(n + 1, 0);
    map<int, int> mp;
    bool ok = true;
    auto dfs = [&](auto &&self, int u, int p) -> void {
      if (was[u]) {
        return;
      }
      was[u] = 1;
      for (auto [v, w] : adj[u]) {
        if (v == p) {
          continue;
        }
        int nxt = ans[u] + w;
        dbg(nxt, ans, mp);
        if ((!was[v] && !mp.count(nxt)) ||
            (was[v] && ans[v] == nxt && mp.count(nxt) && mp[nxt] == v)) {
          mp[nxt] = v;
          ans[v] = nxt;
          self(self, v, u);
        } else {
          dbg(u, v, w, nxt, ans[v]);
          ok = false;
          return;
        }
      }
    };

    mp[0] = 1;
    dfs(dfs, 1, 1);

    if (ok) {
      for (int i = 1; i <= n; i++) {
        if (!was[i]) {
          cout << "? ";
        } else {
          cout << ans[i] << ' ';
        }
      }
      cout << '\n';
    } else {
      cout << "-1\n";
    }
  }
}
