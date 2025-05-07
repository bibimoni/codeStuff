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

class Dsu {
  vector<int> parent, size;

public:
  Dsu() {}
 
  Dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
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
      if (size[a] < size[b]) {
        swap(a, b);
      }
      parent[b] = a;
      size[a] += size[b];
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({w, u, v});
    }
    for (int j = 30; j >= 0; j--) {
      Dsu dsu(n + 1);
      vector<array<int, 3>> n_edges;
      for (auto [w, u, v] : edges) {
        if (((w >> j) & 1) == 0) {
          n_edges.push_back({w, u, v});
          dsu.unite(u, v);
        }
      }
      bool ok = true;
      for (int u = 2; u <= n; u++) {
        ok &= dsu.find(1) == dsu.find(u);
      }
      if (ok) {
        swap(edges, n_edges);
      }
    }
    sort(edges.begin(), edges.end());
    Dsu dsu(n + 1);
    int ans = 0;
    for (auto [w, u, v] : edges) {
      if (dsu.unite(u, v)) {
        ans |= w;
      }
    }
    cout << ans << '\n';
  }
}

