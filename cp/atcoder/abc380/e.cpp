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

public:
  vector<int> parent, size;
  vector<int> color;
  vector<int> l, r;
  Dsu() {}
 
  Dsu(int n) {
    color.resize(n);
    parent.resize(n);
    l.resize(n);
    r.resize(n);
    size.assign(n, 1);
    iota(parent.begin(), parent.end(), int(0));
    iota(color.begin(), color.end(), int(0));
    iota(l.begin(), l.end(), int(0));
    iota(r.begin(), r.end(), int(0));
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
    if (color[a] != color[b]) {
      return false;
    }
    if (a != b) {
      if (size[a] < size[b]) {
        swap(a, b);
      }
      parent[b] = a;
      size[a] += size[b];
      l[a] = min(l[a], l[b]);
      r[a] = max(r[a], r[b]);
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  Dsu dsu(n + 1);
  vector<int> cnt(n + 1, 1);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, c;
      cin >> x >> c;
      int id = dsu.find(x);
      int old = dsu.color[id];
      cnt[old] -= dsu.size[id];
      cnt[c] += dsu.size[id];
      dsu.color[id] = c;
      int lhs = dsu.l[id] - 1;
      int rhs = dsu.r[id] + 1;
      if (lhs >= 1) {
        dsu.unite(lhs, x);
      }
      if (rhs <= n) {
        dsu.unite(rhs, x);
      }
    } else {
      int c;
      cin >> c;
      cout << cnt[c] << "\n";
    }
  }
}


