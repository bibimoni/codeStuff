/**
 * Author: distiled
 */
#include <algorithm>
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
  // vector<vector<int>> gr;
  Dsu() {}

  Dsu(int n) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
    parent.resize(n);
    siz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
    // gr.resize(n);
    // for (int i = 0; i < n; i++) {
    //   gr[i].push_back(i);
    // }
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
      // for (auto x : gr[b]) {
      //   gr[a].push_back(x);
      // }
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
  vector<int> p(n + 1);
  Dsu dsu(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    dsu.unite(p[i], i);
  }

  int64_t ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dsu.find(i) == i) {
      int sz = dsu.size(i);
      ans += 1ll * sz * (sz - 1) / 2;
    }
  }

  cout << ans << '\n';
}
