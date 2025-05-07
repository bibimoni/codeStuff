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

const int INF = 1e18;

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
  void build(const vector<int> &a) {
    build(a, 1, 1, n);
  }

  T combine(int id, int l, int r, int vl, int vr, int sl, int sr) {
    return pair<int, int>{max(vl, sl + vr), sl + sr};
  }

  void build(const vector<int>& a, int id, int l, int r) {
    if(l == r) {
      st[id] = {a[l], a[l]};
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = combine(id, l, r, st[id * 2].first, st[id * 2 | 1].first, st[id * 2].second, st[id * 2 | 1].second);
  }
  void update(int pos, int inc) {
    update(pos, inc, 1, 1, n);
  }
  void update(int pos, int inc, int id, int l, int r) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id] = {inc, inc};
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    st[id] = combine(id, l, r, st[id * 2].first, st[id * 2 | 1].first, st[id * 2].second, st[id * 2 | 1].second);
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return {0, 0};
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    auto ql = query(u, v, id * 2, l, mid);
    auto qr = query(u, v, id * 2 | 1, mid + 1, r);
    return combine(id, l, r, ql.first, qr.first, ql.second, qr.second);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  SegTree<pair<int, int>> st(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int k, u;
      cin >> k >> u;
      st.update(k, u);
    } else {
      int l, r;
      cin >> l >> r;
      cout << max(int(0), st.query(l, r).first) << '\n';
    }
  }
}

