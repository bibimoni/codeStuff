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
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  struct I {
    set<pair<int, int>, greater<pair<int, int>>> st;
    map<int, pair<int, int>> mp;
    I() {}
    I(int u) { st.insert({0, u}); }

    pair<int, int> add(int v, int best, int cand = 0, bool del = false) {
      mp[v] = {best, cand};
      st.insert({best, cand});
      if (del) {
        st.erase(*st.rbegin());
        return *st.rbegin();
      }
      return {};
    }
    pair<int, int> best() { return *st.begin(); }
    array<int, 3> rem(int v) {
      auto p = mp[v];
      array<int, 3> t = {v, p.first, p.second};
      mp.erase(v);
      st.erase(p);
      return t;
    }
  };

  vector<I> dp(n + 1);
  for (int u = 1; u <= n; u++) {
    dp[u] = I(u);
  }

  auto dfs_root = [&](auto &&self, int u, int p) -> void {
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      self(self, v, u);
      auto [b, c] = dp[v].best();
      dp[u].add(v, b + 1, c);
    }
  };

  dfs_root(dfs_root, 1, 1);

  vector<int> ans(n + 1);
  auto dfs = [&](auto &&self, int u, int p) -> void {
    ans[u] = dp[u].best().second;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      auto old_rem_u = dp[u].rem(v);
      auto [b, c] = dp[u].best();
      auto old_add_v = dp[v].add(u, b + 1, c, true);
      self(self, v, u);
      dp[v].rem(u);
      dp[v].add(old_add_v.first, old_add_v.second);
      // dp[v].add()
      dp[u].add(old_rem_u[0], old_rem_u[1], old_rem_u[2]);
    }
  };
  dfs(dfs, 1, 1);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
}
