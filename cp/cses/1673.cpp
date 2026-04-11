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

struct Edge {
  int from, to, cost;
  Edge(int _f, int _t, int _c) : from(_f), to(_t), cost(_c) {}
};

struct BellmanFord {
  vector<int64_t> d;
  bool hasNeg;
  vector<int> path;
  const int64_t INF = 1e18;
  BellmanFord(int n, vector<Edge> edges, int src = 1) {
    hasNeg = false;
    d.assign(n + 1, INF);
    d[src] = 0;
    vector<int> p(n + 1, -1);
    int x;
    for (int i = 0; i < n; i++) {
      x = -1;
      for (Edge e : edges) {
        if (d[e.from] < INF) {
          if (d[e.to] > d[e.from] + e.cost) {
            d[e.to] = d[e.from] + e.cost;
            p[e.to] = e.from;
            x = e.to;
          }
        }
      }
    }
    hasNeg = x != -1;
    if (hasNeg) {
      int y = x;
      for (int i = 0; i < n; ++i)
        y = p[y];

      for (int cur = y;; cur = p[cur]) {
        path.push_back(cur);
        if (cur == y && path.size() > 1)
          break;
      }
      reverse(path.begin(), path.end());
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Edge> e;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e.push_back({u, v, -w});
    adj[v].push_back(u);
  }

  BellmanFord b(n, e);
  vector<int> was(n + 1, 0);
  bool inf = false;
  set<int> st;
  for (auto edge : e) {
    if (b.d[edge.to] == b.INF) {
      continue;
    }
    int64_t cur = b.d[edge.to];
    b.d[edge.to] = min(b.d[edge.to], b.d[edge.from] + edge.cost);
    if (b.d[edge.to] < cur) {
      st.insert(edge.to);
    }
  }

  auto dfs = [&](auto &&self, int u) -> void {
    inf |= st.find(u) != st.end();
    was[u] = 1;
    for (int v : adj[u]) {
      if (was[v]) {
        continue;
      }
      self(self, v);
    }
  };

  if (b.hasNeg)
    dfs(dfs, n);

  if (inf) {
    cout << "-1\n";
  } else {
    cout << -b.d[n] << '\n';
  }
}
