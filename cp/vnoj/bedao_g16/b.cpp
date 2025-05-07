// time-limit: 3000
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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  vector<array<int, 3>> edges;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    edges.push_back({u, v, w});
  }

  int sccs_count = 0;
  vector<int> id(n + 1, 0), low(n + 1);
  vector<int> was(n + 1, 0);
  vector<int> root(n + 1);
  int time_dfs = 0;
  stack<int> st;
  auto dfs = [&] (auto &&self, int u) -> void {
    time_dfs += 1;
    low[u] = id[u] = time_dfs;
    st.push(u);
    for (auto [w, v] : adj[u]) {
      if (was[v]) {
        continue;
      }
      if (!id[v]) {
        self(self, v);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], id[v]);
      }
    }
    if (low[u] == id[u]) {
      sccs_count += 1;
      int v;
      do {
        v = st.top();
        st.pop();
        was[v] = 1;
        root[v] = sccs_count;
      } while (u != v);
    }
  };
  dfs(dfs, 1);

  auto calc = [&] (int x) -> int {
    int ret = 0;
    do {
      ret += x;
      x /= 2;
    } while (x > 0);
    return ret;
  };

  vector<vector<pair<int, int>>> g(sccs_count + 1);
  vector<int> val(sccs_count + 1);
  for (auto p : edges) {
    int u = p[0], v = p[1], w = p[2];
    if (root[u] == root[v]) {
      val[root[u]] += calc(w);
    } else {
      g[root[u]].push_back({w, root[v]});
    }
  }

  vector<int> memo(sccs_count + 1, -1);
  auto dp = [&] (auto &&self, int u) -> int {
    if (g[u].empty()) {
      return val[u];
    }
    if (memo[u] != -1) {
      return memo[u];
    }
    int cur = 0;
    for (auto [w, v] : g[u]) {
      cur = max(cur, self(self, v) + w + val[u]);
    }
    return (memo[u] = cur);
  };

  cout << dp(dp, root[1]);
} 


