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
  SegTree(int _n) : n(_n) {
    T default_value = {0, 0};
    st.assign(4 * n + 5, default_value);
  }
  T cmp(T a, T b) {
    if (a.first > b.first) {
      return a;
    }
    return b;
  }
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T>& a, int id, int l, int r) {
    if(l == r) {
      st[id] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = cmp(st[id * 2], st[id * 2 | 1]);
  }
  void update(int pos, int inc) {
    update(pos, inc, 1, 1, n);
  }
  void update(int pos, int inc, int id, int l, int r) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id] = {inc, l};
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    st[id] = cmp(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return {-1, 0};
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return cmp(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};
 
template <class T>
class Fenwick {
  vector<T> a;
  int n;

public:
  Fenwick() {}

  Fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n + 5, static_cast<T>(0));
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q += a[r]; // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] += del; //check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  freopen("modulo.inp", "r", stdin);
  freopen("modulo.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  SegTree<pair<int, int>> st(n);
  Fenwick<int> ft(n + 1);
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    ft.update(i, a[i].first);
    a[i].second = i;
  }
  st.build(a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      cout << ft.query(r) - ft.query(l - 1) << '\n';
    } else if (type == 2) {
      int k, x;
      cin >> k >> x;
      ft.update(k, -a[k].first);
      a[k].first = x;
      ft.update(k, a[k].first);
      st.update(k, a[k].first);
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      auto [_, id] = st.query(l, r);
      while (a[id].first >= x) {
        dbg(id, a[id]);
        ft.update(id, -a[id].first);
        a[id].first %= x;
        ft.update(id, a[id].first);
        st.update(id, a[id].first);
        auto [_, n_id] = st.query(l, r);
        id = n_id;
      }
    }
  }
}
