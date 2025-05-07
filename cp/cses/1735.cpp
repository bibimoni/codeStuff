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
//    LazySegtree<int> seg;
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(l, r, inc); //increase a[l -> r] += inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template <class T>
struct LazySegTree {
  #define LAZY_SET 0
  #define LAZY_ADD 1
  vector<T> st;
  vector<pair<int, int>> lazy;
  int n;
  LazySegTree(int _n) : n(_n) {
    T default_value = 0;
    st.assign(4 * n + 5, default_value);
    lazy.assign(4 * n + 5, {LAZY_ADD, 0});
  }  
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T> &a, int id, int l, int r) {
    lazy[id] = {LAZY_ADD, 0};
    if(l == r) {
      if(l < (int)a.size()) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }

  pair<int, int> combineLZ(pair<int, int> lhs, pair<int, int> rhs) {
    vector<pair<int, int>> cv(4);
    int cur = (lhs.first << 1) | rhs.first;
    cv[0b01] = pair<int, int>{LAZY_SET, lhs.second + rhs.second}; // lz_set <- lz_add = lz_set
    cv[0b11] = pair<int, int>{LAZY_ADD, lhs.second + rhs.second}; // lz_add <- lz_add = lz_add
    cv[0b10] = pair<int, int>{LAZY_SET, rhs.second}; // lz_add <- lz_set = lz_set
    cv[0b00] = pair<int, int>{LAZY_SET, rhs.second}; // lz_set <- lz_set = lz_set
    return cv[cur];
  }

  int addST(int lhs, pair<int, int> rhs, int l, int r) {
    if (rhs.first == LAZY_ADD) {
      return lhs + rhs.second * (r - l + 1);
    } 
    return rhs.second * (r - l + 1);
  }

  void down(int id, int l, int r) {
    int mid = (r + l) >> 1;
    lazy[id * 2] = combineLZ(lazy[id * 2], lazy[id]);
    lazy[id * 2 | 1] = combineLZ(lazy[id * 2 | 1], lazy[id]);
    st[id * 2] = addST(st[id * 2], lazy[id], l, mid);
    st[id * 2 | 1] = addST(st[id * 2 | 1], lazy[id], mid + 1, r);
    lazy[id] = {LAZY_ADD, 0};
  }
  void update(int u, int v, pair<int, int> val) {
    update(u, v, val, 1, 1, n);
  }
  void update(int u, int v, pair<int, int> val, int id, int l, int r) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] = combineLZ(lazy[id], val);
      if (val.first == LAZY_ADD) {
        st[id] += val.second * (r - l + 1);
      } else {
        st[id] = val.second * (r - l + 1);
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
  int n, q;
  cin >> n >> q;
  LazySegTree<int> st(n);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      st.update(l, r, {LAZY_ADD, x});
    } else if (type == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      st.update(l, r, {LAZY_SET, x});
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r) << '\n';
    }
  }
}

