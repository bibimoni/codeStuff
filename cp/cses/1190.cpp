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
    T default_value = array<int, 4>{0, 0, 0, 0};
    st.assign(4 * n + 5, default_value);
  }
  void build(const vector<int> &a) {
    build(a, 1, 1, n);
  }

  T combine(T lhs, T rhs) {
    return T{
      max({lhs[2] + rhs[1], lhs[0], rhs[0]}),
      max({lhs[1], lhs[3] + rhs[1]}),
      max({rhs[2], rhs[3] + lhs[2]}),
      lhs[3] + rhs[3]
    };
  }

  void build(const vector<int>& a, int id, int l, int r) {
    if(l == r) {
      st[id] = {max(int(0), a[l]), a[l], a[l], a[l]};
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 | 1]);
  }
  void update(int pos, int inc) {
    update(pos, inc, 1, 1, n);
  }
  void update(int pos, int inc, int id, int l, int r) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id] = {max(int(0), inc), inc, inc, inc};
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 | 1]);
  }
  int query() {
    return st[1][0];
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  SegTree<array<int, 4>> st(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(a);
  while (q--) {
    int k, x;
    cin >> k >> x;
    st.update(k, x);
    cout << st.query() << '\n';
  }
}

