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
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> ll;
  auto check = [&](int w, int bit) -> bool {
    bool ok = true;
    for (int b : ll) {
      ok &= ((w >> b) & 1) == 0;
    }
    return ok && ((w >> bit) & 1) == 0;
  };

  auto rem = [&](int bit) -> bool {
    vector<int> was(n + 1, 0);
    vector<pair<int, int>> ue;
    auto dfs = [&](auto &&self, int u, int p) -> void {
      was[u] = 1;
      for (auto [v, w] : adj[u]) {
        if (!check(w, bit)) {
          continue;
        }
        if (v == p) {
          continue;
        }
        if (!was[v]) {
          self(self, v, u);
        }
      }
    };

    dfs(dfs, 1, 1);
    // can visit n
    if (was[n]) {
      ll.push_back(bit);
    }
    return was[n];
  };

  int ans = 0;
  for (int bit = 31; bit >= 0; bit--) {
    if (!rem(bit)) {
      ans |= (int(1) << bit);
    }
  }
  cout << ans << '\n';
}
