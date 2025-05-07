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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.push_back({u, v});
  }
  int s1, t1, l1;
  cin >> s1 >> t1 >> l1;
  int s2, t2, l2;
  cin >> s2 >> t2 >> l2;

  const int INF = int(1e9);
  auto dijkstra = [&] (int src) -> vector<int> {
    vector<int> d(n + 1, INF);
    queue<pair<int, int>> que;
    que.push({0, src});
    d[src] = 0;
    while (que.size()) {
      auto [w, u] = que.front();
      que.pop();
      if (w != d[u]) {
        continue;
      }
      for (int v : adj[u]) {
        if (d[v] < d[u] + 1) {
          d[v] = d[u] + 1;
          que.push({d[v], v});
        }
      }
    }
    return d;
  };
  auto d_1 = dijkstra(s1);
  auto d_r1 = dijkstra(t1);
  auto d_2 = dijkstra(s2);
  auto d_r2 = dijkstra(t2);
  vector<vector<int>> g(n + 1);
  int n_edges = 0;
  for (auto [u, v] : edges) {
    if (d_1[u] + 1 + d_r1[v] == d_1[t1]) {
      g[u].push_back(v);
      g[v].push_back(u);
      n_edges += 1;
    } else if (d_2[u] + 1 + d_r2[v] == d_2[t2]) {
      g[u].push_back(v);
      g[v].push_back(u);
      n_edges += 1;
    }
  }
  int ans = edges.size() - n_edges;

}


