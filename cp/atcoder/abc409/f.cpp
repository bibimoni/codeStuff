/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

class Dsu {
  int count_cp;

public:
  vector<int> parent, siz;
  Dsu() {}

  Dsu(int n) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
    parent.resize(n);
    siz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
  }

  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find(parent[v]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (siz[a] < siz[b]) {
        swap(a, b);
      }
      parent[b] = a;
      siz[a] += siz[b];
      count_cp -= 1;
      return true;
    } else {
      return false;
    }
  }

  int size(int u) { return siz[find(u)]; }

  int size() { return count_cp; }

  bool same(int u, int v) { return find(u) == find(v); }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> pts(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> pts[i].first >> pts[i].second;
  }

  auto calc = [&](pair<int, int> &i, pair<int, int> &j) -> int {
    return abs(i.first - j.first) + abs(i.second - j.second);
  };

  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
      pq;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }
      pq.push({calc(pts[i], pts[j]), i, j});
    }
  }

  Dsu dsu(n + q + 1);
  while (q--) {
    int taipu;
    cin >> taipu;
    if (taipu == 1) {
      int a, b;
      cin >> a >> b;
      n += 1;
      pts.push_back({a, b});
      for (int i = 1; i < n; i++) {
        pq.push({calc(pts[i], pts[n]), i, n});
      }
    } else if (taipu == 2) {
      int mn = -1;
      while (pq.size()) {
        auto p = pq.top();
        int dist = p[0], u = p[1], v = p[2];
        if (!dsu.same(u, v)) {
          if (mn == -1) {
            mn = dist;
          }
          if (dist != mn) {
            break;
          }
          dsu.unite(u, v);
        }
        pq.pop();
      }
      cout << mn << '\n';
    } else {
      int u, v;
      cin >> u >> v;
      cout << (dsu.same(u, v) ? "Yes\n" : "No\n");
    }
  }
}
