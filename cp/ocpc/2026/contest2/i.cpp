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
  int k;
  cin >> k;
  vector<pair<int, int>> l(k);
  for (int i = 0; i < k; i++) {
    cin >> l[i].first >> l[i].second;
  }

  int m;
  cin >> m;
  vector<pair<int, int>> sw(m);
  for (int i = 0; i < m; i++) {
    cin >> sw[i].first >> sw[i].second;
  }

  vector<int> s;
  for (auto [u, v] : l) {
    s.push_back(u);
    s.push_back(v + 1);
  }

  for (auto [u, v] : sw) {
    s.push_back(u);
    s.push_back(v + 1);
  }

  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());

  auto findd = [&](int v) -> int {
    return int(lower_bound(s.begin(), s.end(), v) - s.begin() + 1);
  };

  const int N = int(s.size() + 1);
  vector<int> val(N + 1);
  for (auto [u, v] : l) {
    val[findd(u)] ^= 1;
    val[findd(v + 1)] ^= 1;
  }

  vector<vector<pair<int, int>>> adj(N + 1);
  for (int i = 0; i < m; i++) {
    auto [u, v] = sw[i];
    adj[findd(u)].push_back({findd(v + 1), i});
    adj[findd(v + 1)].push_back({findd(u), i});
  }

  vector<int> was(N + 1), ans(m);
  auto dfs = [&](auto &&self, int u, int p) -> void {
    was[u] = 1;
    for (auto [v, idx] : adj[u]) {
      if (p == v || was[v]) {
        continue;
      }
      self(self, v, u);
      if (val[v] == 1) {
        ans[idx] = 1;
        val[v] ^= 1;
        val[u] ^= 1;
      }
    }
  };

  for (int i = 1; i <= N; i++) {
    if (!was[i]) {
      dfs(dfs, i, i);
    }
  }

  bool ok = true;
  for (int i = 1; i <= N; i++) {
    ok &= val[i] == 0;
  }

  if (!ok) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
      cout << ans[i] << " \n"[i == m - 1];
    }
  }
}
