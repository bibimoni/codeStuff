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
  BellmanFord(int n, vector<Edge> edges, int src = 1) {
    const int64_t INF = 1e18;
    hasNeg = false;
    d.assign(n + 1, INF);
    d[src] = 0;
    vector<int> p(n + 1, -1);
    int x;
    for (int i = 0; i <= n; i++) {
      x = -1;
      for (Edge e : edges) {
        // if (d[e.from] < INF) {
        if (d[e.to] > d[e.from] + e.cost) {
          d[e.to] = d[e.from] + e.cost;
          p[e.to] = e.from;
          x = e.to;
        }
        // }
      }
    }
    hasNeg = x != -1;
    // dbg(hasNeg);
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
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    e.push_back({u, v, c});
  }

  BellmanFord bf(n + 1, e);
  if (bf.hasNeg) {
    cout << "YES\n";
    for (int i = 0; i < (int)bf.path.size(); i++) {
      cout << bf.path[i] << " ";
    }
  } else {
    cout << "NO\n";
  }
}
