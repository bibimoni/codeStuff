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
// #define int int64_t

// segtree with one-based indexing
// supports range update
//
// build:
// SegTree<T, F, U> seg(<cap>, <default>, <trash>)
// SegTree<int, F, U>
//  st_mn(n, 0, int(1e9));
//
//  vector<int> a(n + 1);
//  seg.build(a); // vector `a` must be one-indexed
//
// update:
//    seg.update(l, r, inc); // apply a[l -> r] = U(a[l -> r], inc)
//
// query:
//    seg.query(l, r)

#if __cplusplus >= 201703L

template <class T, auto F, auto U> struct SegTree {
  static_assert(is_convertible_v<decltype(F), function<T(T, T)>>,
                "F must be T(T, T)");
  static_assert(is_convertible_v<decltype(U), function<T(T, T)>>,
                "U must be T(T, T)");

#else

template <class T, T (*F)(T, T), T (*U)(T, T)> struct SegTree {

#endif

  vector<T> st, lazy;
  int n;
  T trash_val;
  T default_value;
  SegTree() : SegTree(0) {}
  explicit SegTree(int _n, T _default_value, T _trash_val)
      : n(_n), trash_val(_trash_val), default_value(_default_value) {
    st.assign(4 * n + 5, default_value);
    lazy.assign(4 * n + 5, default_value);
  }

  // one-indexed
  void build(const vector<T> &a) { build(a, 1, 1, n); }
  void build(const vector<T> &a, int id, int l, int r) {
    lazy[id] = default_value;
    if (l == r) {
      if (l < (int)a.size()) {
        st[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = F(st[id * 2], st[id * 2 | 1]);
  }

  // void down(int id) {
  //   if (lazy[id] == default_value) {
  //     return;
  //   }
  //   st[id * 2] = U(st[id * 2], lazy[id]);
  //   st[id * 2 | 1] = U(st[id * 2 | 1], lazy[id]);
  //   lazy[id * 2] = U(lazy[id * 2], lazy[id]);
  //   lazy[id * 2 | 1] = U(lazy[id * 2 | 1], lazy[id]);
  //   lazy[id] = default_value;
  // }

  void update(int u, int v, T val) { update(u, v, val, 1, 1, n); }
  void update(int i, T val) { update(i, i, val, 1, 1, n); }
  void update(int u, int v, T val, int id, int l, int r) {
    if (l > r || v < l || r < u)
      return;
    if (u <= l && r <= v) {
      // lazy[id] = U(lazy[id], val);
      st[id] = U(st[id], val);
      return;
    }
    // down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = F(st[id * 2], st[id * 2 | 1]);
  }

  T query(int u, int v) { return query(u, v, 1, 1, n); }
  T query(int i) { return query(i, i, 1, 1, n); }
  T query(int u, int v, int id, int l, int r) {
    if (v < l || r < u) {
      return trash_val;
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    // down(id);
    return F(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

int64_t F(int64_t u, int64_t v) { return min(u, v); }
int64_t F2(int64_t u, int64_t v) { return max(u, v); }
int64_t U(int64_t _, int64_t v) { return v; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  SegTree<int64_t, F, U> st_mn_z(n, 0, int64_t(1e18));
  SegTree<int64_t, F, U> st_mn_w(n, 0, int64_t(1e18));
  SegTree<int64_t, F2, U> st_mx_z(n, 0, int64_t(-1e18));
  SegTree<int64_t, F2, U> st_mx_w(n, 0, int64_t(-1e18));

  auto set = [&](int id, int x, int y) -> void {
    st_mn_z.update(id, x + y);
    st_mx_z.update(id, x + y);
    st_mn_w.update(id, x - y);
    st_mx_w.update(id, x - y);
  };

  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    set(i, x, y);
  }

  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int i, x, y;
      cin >> i >> x >> y;
      set(i, x, y);
    } else if (opt == 2) {
      int l, r, x, y;
      cin >> l >> r >> x >> y;
      int64_t mxz = st_mx_z.query(l, r);
      int64_t mnz = st_mn_z.query(l, r);
      int64_t mxw = st_mx_w.query(l, r);
      int64_t mnw = st_mn_w.query(l, r);
      int z = x + y, w = x - y;
      cout << max({abs(mxz - z), abs(z - mnz), abs(mxw - w), abs(w - mnw)})
           << '\n';
    }
  }
}
