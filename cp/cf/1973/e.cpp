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
#define int long long
#define all(_x) (_x).begin(), (_x).end()

class dsu {
  vector<int> parent, size;

public:
  vector<set<int>> e;
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
    e.resize(n);
    for(int i = 1; i < n; i++) {
      e[i].insert(i);
    }
    dbg(e);
  }
 
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
 
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
      for(auto c : e[b]) {
        e[a].insert(c);
      }
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
  while(tt--) {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    dsu dsu(n + 1);
    for(int i = 1; i <= n; i++) {
      dsu.unite(p[i], i);
    }
    int lo = 2, hi = 2 * n;
    for(int i = 1; i <= n; i++) {
      if(dsu.find(i) == i && dsu.e[i].size() >= 2) {
        auto st = dsu.e[i];
        lo = (*st.begin()) + *next(st.begin());
        // dbg(*st.rbegin(), *(next(st.rbegin())));
        hi = (*st.rbegin()) + *next(st.rbegin());
        dbg(st);
      }
    }
    dbg(lo, hi)
    cout << lo * (2 * n - hi + 1) << '\n';
  }
}

