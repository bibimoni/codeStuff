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
  vector<T> st, lazy;
  int n;
  LazySegTree(int _n) : n(_n) {
    T default_value = 1e9;
    st.assign(4 * n + 5, default_value);
    lazy.assign(4 * n + 5, 0);
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
    st[id] = min(st[id * 2], st[id * 2 | 1]);
  }
  void down(int id) {
    if(lazy[id] == 0)
      return;
    st[id * 2] = lazy[id];
    st[id * 2 | 1] = lazy[id];
    lazy[id * 2] = lazy[id];
    lazy[id * 2 | 1] = lazy[id];
    lazy[id] = 0;
  }
  void update(int u, int v, T val) {
    update(u, v, val, 1, 1, n);
  }
  void update(int u, int v, T val, int id, int l, int r) {
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
    st[id] = min(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return 1e9;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id);
    return min(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  vector<array<int, 4>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    a[i][3] = i; 
  }
  vector<int> cur(w + 1, h + 1);
  LazySegTree<int> st(w);
  st.build(cur);

  sort(a.begin(), a.end(), [&] (array<int, 4> &i, array<int, 4> &j) {
    return i[0] > j[0];
  });

  vector<int> ans(n);
  for (auto p : a) {
    int r = p[0], c = p[1], l = p[2], id = p[3];
    int height = st.query(c, c + l - 1);
    ans[id] = height - 1;
    st.update(c, c + l - 1, ans[id]);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
}


