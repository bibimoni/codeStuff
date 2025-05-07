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
#define int int64_t 
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> ho(n + 1, 0);
    vector<vector<pair<int, int>>> adj(2 * n + 1);
    for (int i = 0; i < h; i++) {
      int x;
      cin >> x;
      adj[x].push_back({x + n, 0});
    }

    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      adj[n + u].push_back({n + v, w / 2});
      adj[n + v].push_back({n + u, w / 2});
    }

    for (int i = 1; i <= n; i++) {
      adj[n + i].push_back({i, 0});
    }

    const int INF = int(1e18);
    auto dijkstra = [&] (int src) -> vector<int> {
      vector<int> d(2 * n + 1, INF);
      set<pair<int, int>> st;
      d[src] = 0;
      st.insert({0, src});
      while (st.size()) {
        auto [w, u] = *st.begin();
        st.erase(st.begin());
        if (d[u] != w) {
          continue;
        }
        for (auto [v, w1] : adj[u]) {
          if (d[v] > d[u] + w1) {
            d[v] = d[u] + w1;
            st.insert({d[v], v});
          }
        }
      }
      return d;
    };

    auto d1 = dijkstra(1);
    auto dn = dijkstra(n);
    // dbg(d1, dn);
    if (d1[n] == INF) {
      cout << "-1\n";
      continue;
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
      ans = min(ans, max(d1[i], dn[i]));
    }
    cout << ans << '\n';
  }
}


