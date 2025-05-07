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

const int MAX_ELEMENT = 6, N = (int) 5;

// lazy propagation with one-based indexing
//
// build:
//    lazySegtree<int, N> seg; // N is constant
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(l, r, inc); //increase a[l -> r] += inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template <class T, int SZ>
struct lazySegTree {
  vector<vector<T>> lazy;
  lazySegTree() {
    T default_value = 0;
    vector<int> tmp(MAX_ELEMENT);
    iota(tmp.begin(), tmp.end(), 0);
    lazy.assign(4 * SZ, tmp);
  }  
  void down(int id) {
    for(int i = 1; i < MAX_ELEMENT; i++) {
      lazy[id * 2][i] = lazy[id][lazy[id * 2][i]];
      lazy[id * 2 | 1][i] = lazy[id][lazy[id * 2 | 1][i]];
      lazy[id][i] = i;
    }
  }
  void update(int u, int v, T x, T y, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      for(int i = 1; i < MAX_ELEMENT; i++)
        if(lazy[id][i] == x)
          lazy[id][i] = y;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, x, y, id * 2, l, mid);
    update(u, v, x, y, id * 2 | 1, mid + 1, r);
  }
  void query(vector<int> &a, int id = 1, int l = 1, int r = SZ) {
    if(l == r) {
      if(l < a.size()) {
        a[l] = lazy[id][a[l]];
      }
      return;
    }
    int mid = (l + r) >> 1;
    down(id);
    query(a, id * 2, l, mid);
    query(a, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  lazySegTree<int, N> seg;
  int q;
  cin >> q;
  while(q--) {
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    seg.update(l, r, x, y);
  }
  seg.query(a);
  for(int i = 1; i <= n; i++)
    cout << a[i] << ' ';
}

