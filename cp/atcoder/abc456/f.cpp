/**
 * Author: distiled
 */
#include<bits/stdc++.h>
#include <optional>
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

const int64_t inf = 1e18;
struct Node {
  int64_t a, b, c, d;
  Node() {
    a = d = 0;
    b = c = inf;
  }
  Node(int64_t _a, int64_t _b, int64_t _c, int64_t _d) : a(_a), b(_b), c(_c), d(_d){}

  static pair<int64_t, int64_t> func(Node x, int64_t u, int64_t v) {
    return {min(x.a + u, x.b + v), min(x.c + u, x.d + v)}; 
  };

  static Node F(Node l, Node r) {
    Node ret;
    auto [t1, t2] = Node::func(r, l.a, l.c);
    auto [t3, t4] = Node::func(r, l.b, l.d);
    ret.a = t1;
    ret.c = t2;
    ret.b = t3;
    ret.d = t4;
    return ret;
  } 
  static Node U(Node _, Node r) {
    Node ret;
    return r;
  }
  bool operator==(const Node &o) const {
    return o.a == a and o.b == b and o.c == c and o.d == d;
  }
};


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    vector<Node> b(n + 1);
    for (int i = 1; i <= n; i++) {
      b[i].a = inf;
      b[i].b = 0;
      b[i].c = a[i];
      b[i].d = a[i];
    }
    /*
       a, b - u -> v' v' = min(a + u, v + b) -> min()
       c, d - v    u' u' = min(c + u, v + d)
     inf, 0 - u -> min(u + inf, v + 0) = u = dp[1]
       w, w - v -> min(u + w, v + w) = v = dp[0]

       inf 0 -> inf 0-> inf 0 -> inf 0
       3 3      22 22   39 39    4 4
           22 26     39 39   4  4 
           26 3      61 22   43 39 
                
                
       */
    SegTree<Node, Node::F, Node::U>
      st(n, Node(), Node());
    st.build(b);

    int64_t ans = inf;
    for (int i = k; i <= n; i++) {
      dbg(i);
      Node x = st.query(i - k + 1, i);
      dbg(x.a, x.b, x.c, x.d);
      int64_t dp0 = 0, dp1 = (i - k + 1 == 1 ? inf : a[i - k]);
      auto [x1, x2] = Node::func(x, dp0, dp1);
      ans = min(x2, ans);
    }

    cout << ans << '\n';
  } 
}
