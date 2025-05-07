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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    auto dijkstra = [&] (int src) -> void {
      d[src] = 0;
      set<pair<int, int>> st;
      st.insert({d[src], src});
      while (st.size()) {
        auto [w_1, u] = *st.begin();
        st.erase(st.begin());
        if (d[u] != w_1) {
          continue;
        }
        for (int v : adj[u]) {
          if (d[v] > d[u] + 1) {
            d[v] = d[u] + 1;
            st.insert({d[v], v});
          } 
        }
      }
    };

    dijkstra(1);  

    vector<int> dp(n + 1);
    vector<int> was(n + 1, 0);
    auto dfs = [&] (auto &&self, int u) -> void {
      was[u] = 1;
      dp[u] = d[u];
      for (int v : adj[u]) {
        if (!was[v] && d[u] < d[v]) {
          self(self, v);
        }
        if (d[u] < d[v]) {
          dp[u] = min(dp[u], dp[v]);
        } else {
          dp[u] = min(dp[u], d[v]);
        }
      }
    };
    dfs(dfs, 1);
    for (int i = 1; i <= n; i++) {
      cout << dp[i] << " \n"[i == n];
    }
  }
}

