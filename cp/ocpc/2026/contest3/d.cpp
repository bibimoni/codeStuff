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

class Dsu {
  vector<int> parent, siz;
  int count_cp;

public:
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
  int n;
  cin >> n;
  map<int, vector<int>> xs, ys;
  vector<int> xc, yc;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    xs[x].push_back(i);
    ys[y].push_back(i);
    xc.push_back(x);
    yc.push_back(y);
  }

  Dsu dsu(n);
  for (auto &[_, p] : xs) {
    for (int i = 1; i < int(p.size()); i++) {
      dsu.unite(p[0], p[i]);
    }
  }

  for (auto &[_, p] : ys) {
    for (int i = 1; i < int(p.size()); i++) {
      dsu.unite(p[0], p[i]);
    }
  }

  vector<int> sz;
  for (int i = 0; i < n; i++) {
    if (dsu.find(i) == i) {
      sz.push_back(dsu.size(i));
    }
  }

  sort(sz.begin(), sz.end(), greater<>());
  int ans = sz[0] + 1;
  if (sz.size() > 1) {
    ans += sz[1];
  }

  cout << ans << '\n';
}
