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

struct Node {
  int val, mx, mn;
  bool lfirst;
  Node(bool _lfirst = true) {
    lfirst = _lfirst;
    mx = 2e9, 
    mn = 2e9,
    val = -1;
  }

  void update(int _tt) {
    val = 0;
    mx = _tt;
    mn = _tt;
  }
  
  Node operator+ (Node const& o) {
    Node ret = Node(lfirst);
    if (val == -1) {
      return o;
    }
    if (o.val == -1) {
      return *this;
    }
    ret.val = max({val, o.val, lfirst ? mx - o.mn : o.mx - mn});
    ret.mx = max(mx, o.mx);
    ret.mn = min(mn, o.mn);
    return ret;
  }
  friend ostream& operator<<(ostream& out, Node const& o) {
    return out << o.val << ' ' << o.mx << ' ' << o.mn << '\n';
  }
};

// segtree with one-based indexing
//
// build:
//    SegTree<int> seg(n); // vector<int> a(n + 1)
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(pos, inc); //increase a[pos] to a[pos] + inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template<class T>
struct SegTree {
  vector<T> st;
  int n;
  bool lfirst;
  SegTree(int _n, bool _lfirst) : n(_n), lfirst(_lfirst) {
    T default_value = T(lfirst);
    st.assign(4 * n + 5, default_value);
  }
  void build(const vector<int> &a) {
    build(a, 1, 1, n);
  }
  void update(int pos, int t) {
    update(pos, t, 1, 1, n);
  }
  void update(int pos, int t, int id, int l, int r) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id].update(t);
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, t, id * 2, l, mid);
    update(pos, t, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return Node(lfirst);
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    SegTree<Node> st1(n, true), st2(n, false);
    for (int i = 1; i <= n; i++) {
      st1.update(i, a[i] + i);
      st2.update(i, a[i] - i);
    }

    auto get_ans = [&] () -> int {
      return max(st1.query(1, n).val, st2.query(1, n).val);
    };

    auto update = [&] (int p, int x) -> void {
      st1.update(p, x + p);
      st2.update(p, x - p);
    };

    cout << get_ans() << '\n';
    while (q--) {
      int p, x;
      cin >> p >> x;
      update(p, x);
      cout << get_ans() << '\n';
    }
  }
}

// max  - min
// a[l] - a[r] - (r - l)
// left - right
// (a[l] + l) - (a[r] + r) 

// max    min
// a[r] - a[l] - (r - l)
// right - left
// (a[r] - r) - (a[l] - l)