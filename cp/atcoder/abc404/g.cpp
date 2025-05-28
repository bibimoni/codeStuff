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

struct Edge {
  int from, to, cost;
  Edge(int _f, int _t, int _c) : from(_f), to(_t), cost(_c) {}
};

struct BellmanFord {
  vector<int> d;
  bool hasNeg;
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
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // B_r - B_l-1 <= s[i]
  // B_r - B_l-1 >= s[i] || -B_r + B_l-1 <= -s[i]
  // B_i - B_i-1 >= -1 || -B_i + B_i-1 <= -1
  // B_n min -> B_0 is max
  int n, m;
  cin >> n >> m;
  vector<Edge> e;
  vector<int> l(m), r(m), s(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> s[i];
    e.push_back(Edge(l[i] - 1, r[i], s[i]));
    e.push_back(Edge(r[i], l[i] - 1, -s[i]));
  }
  for (int i = 1; i <= n; i++) {
    e.push_back(Edge(i, i - 1, -1));
  }
  BellmanFord bell(n + 1, e, n);
  if (bell.hasNeg) {
    cout << "-1\n";
  } else {
    cout << -bell.d[0] << '\n';
  }
}
