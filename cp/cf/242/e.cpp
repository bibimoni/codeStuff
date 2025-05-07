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

// lazy propagation with one-based indexing
//
// build:
//    lazySegtree<int> seg;
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(l, r, inc); //increase a[l -> r] += inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template <class T>
struct lazySegTree {
  vector<T> st, lazy;
  int n;
  lazySegTree(int _n) : n(_n) {
    T default_value = 0;
    st.assign(4 * n, default_value);
    lazy.assign(4 * n, default_value);
  }  
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T> &a, int id, int l, int r) {
    lazy[id] = 0;
    if(l == r) {
      if(l < a.size()) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  void down(int id, int l, int r) {
    if(lazy[id] == 0)
      return;
    int m = (l + r) >> 1;
    st[id * 2] = (m - l + 1) - st[id * 2];
    st[id * 2 | 1] = (r - m) - st[id * 2 | 1];
    lazy[id * 2] ^= 1;
    lazy[id * 2 | 1] ^= 1;
    lazy[id] = 0;
  }
  void update(int u, int v, T val) {
    update(u, v, val, 1, 1, n);
  }
  void update(int u, int v, T val, int id, int l, int r) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      if (val == 1) {
        lazy[id] ^= 1;
        st[id] = (r - l + 1) - st[id];
      }
      return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return 0;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  const int LG = 20;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<lazySegTree<int>> st(LG, lazySegTree<int>(n + 1));
  for (int j = 0; j < LG; j++) {
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      b[i] = (a[i] >> j) & 1;
    }
    st[j].build(b);
  }
  int m;
  cin >> m;
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      int ans = 0;
      for (int j = 0; j < LG; j++) {
        ans += st[j].query(l, r) * (1ll << j);
      }
      cout << ans << '\n';
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      for (int j = 0; j < LG; j++) {
        st[j].update(l, r, (x >> j) & 1);
      }
    }
  }
  // sum a[l] + a[l + 1] + ... + a[r]
  // sum i : [l..r] sum j : [0..19] 2^j * b[i][j]
  // sum j : [0..19] 2^j * sum i : [l..r] b[i][j]

}

