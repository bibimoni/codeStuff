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
  vector<int> par, sz;
  int n;
public: 
  vector<vector<int>> gr;
  Dsu() {}
  Dsu(int _n) : n(_n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    sz.assign(n, 1);
    gr.resize(n);
    for (int i = 0; i < n; i++) {
      gr[i].push_back(i);
    }
  }

  int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      return false;
    } else {
      if (sz[u] > sz[v]) {
        swap(u, v);
      }
      sz[u] += sz[v];
      par[v] = u;
      for (int x : gr[v]) {
        gr[u].push_back(x);
      }
      sort(gr[u].begin(), gr[u].end(), greater<int>());
      while (gr[u].size() > 10) {
        gr[u].pop_back();
      }
      return true;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> adj(n + 1);
  Dsu dsu(n + 1);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      dsu.unite(u, v);
    } else if (t == 2) {
      int v, k;
      cin >> v >> k;
      v = dsu.find(v);
      if (int(dsu.gr[v].size()) < k) {
        cout << "-1\n";
      } else {
        cout << dsu.gr[v][k - 1] << '\n';
      }
    }
  }
}


