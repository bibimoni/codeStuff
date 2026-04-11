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

class Dsu {
  vector<int> parent, siz;
  int count_cp;

public:
  vector<set<int>> black;
  Dsu() {}

  Dsu(int n) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
    parent.resize(n);
    siz.assign(n, 1);
    black.assign(n, set<int>{});
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
      for (int v : black[b]) {
        black[a].insert(v);
      }
      count_cp -= 1;
      return true;
    } else {
      return false;
    }
  }

  void change(int u, int color) {
    int root = find(u);
    if (color == 1) {
      black[root].erase(u);
    } else {
      black[root].insert(u);
    }
  }

  bool good(int u) {
    int root = find(u);
    return black[root].size() > 0;
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
  vector<int> c(n + 1, 1);

  Dsu dsu(n + 1);

  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int u, v;
      cin >> u >> v;
      dsu.unite(u, v);
    } else if (opt == 2) {
      int v;
      cin >> v;
      c[v] ^= 1;
      dsu.change(v, c[v]);
    } else if (opt == 3) {
      int v;
      cin >> v;
      cout << (dsu.good(v) ? "Yes\n" : "No\n");
    }
  }
}
