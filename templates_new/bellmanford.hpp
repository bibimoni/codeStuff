struct Edge {
  int from, to, cost;
  Edge(int _f, int _t, int _c) : from(_f), to(_t), cost(_c) {}
};

struct BellmanFord {
  vector<int> d;
  bool hasNeg;
  vector<int> path;
  BellmanFord(int n, vector<Edge> edges, int src = 1) {
    const int INF = 1e9;
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
