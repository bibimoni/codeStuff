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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    Dsu dsu_f(n + 1);
    vector<pair<int, int>> e_f;
    for (int i = 0; i < m1; i++) {
      int u, v;
      cin >> u >> v;
      dsu_f.unite(u, v);
      e_f.emplace_back(u, v);
    }
    Dsu dsu_g(n + 1);
    vector<pair<int, int>> e_g;
    for (int i = 0; i < m2; i++) {
      int u, v;
      cin >> u >> v;
      // dsu_g.unite(u, v);
      e_g.emplace_back(u, v);
    }
    int ans = 0;
    for(const auto& [u, v] : e_f) {
      if (dsu_g.unite(u, v)) {
        
      }
    }
  }
}


