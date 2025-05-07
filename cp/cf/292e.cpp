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
  vector<T> st, lazy;
  lazySegTree() {
    T default_value = {0, 0};
    st.assign(4 * SZ, default_value);
    lazy.assign(4 * SZ, default_value);
  }  
  void build(const vector<T> &a, int id = 1, int l = 1, int r = SZ) {
    lazy[id] = {0, 0};
    if(l == r) {
      if(l < a.size()) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  void down(int id) {
    if(lazy[id] == pair<int, int>({0, 0}))
      return;
    st[id * 2] = lazy[id];
    st[id * 2 | 1] = lazy[id];
    lazy[id * 2] = lazy[id];
    lazy[id * 2 | 1] = lazy[id];
    lazy[id] = {0, 0};
  }
  void update(int u, int v, T val, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] = val;
      st[id] = val;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) {
      return {0, 0};
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id);
    return max(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

const int N = 1e5 + 5;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<pair<int, int>> paint(n + 1, {0, 0});
  lazySegTree<pair<int, int>, N> seg;
  seg.build(paint);
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int x, y, k;
      cin >> x >> y >> k;
      seg.update(y, y + k - 1, {x, y});
    }
    else if(t == 2) {
      int k;
      cin >> k;
      auto [v, u] = seg.query(k, k);
      if(v == 0) {
        cout << b[k] << '\n';
      }
      else {
        cout << a[v + k - u] << '\n';
      }
    }
  }
  
}

