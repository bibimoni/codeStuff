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
    T default_value = 0;
    st.assign(4 * n + 5, default_value);
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
    st[id] = min(st[id * 2], st[id * 2 | 1]);
  }
  void update(int pos, T inc) {
    update(pos, inc, 1, 1, n);
  }
  void update(int pos, T inc, int id, int l, int r) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id] += inc;
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    st[id] = min(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return INF;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return min(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  SegTree<int> stp(n), stn(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    stp.update(i, a[i] + i);
    stn.update(i, a[i] - i);
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int k, x;
      cin >> k >> x;
      stp.update(k, x - a[k]);
      stn.update(k, x - a[k]);
      a[k] = x;
    } else {
      int k;
      cin >> k;
      cout << min(k + stn.query(1, k), stp.query(k, n) - k) << '\n';
    }
  }
}

