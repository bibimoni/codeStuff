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
#define int long long

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

template <class T> struct lazySegTree {
  vector<T> lazy;
  vector<pair<int, int>> st;
  int n;
  lazySegTree(int _n) : n(_n) {
    T default_value = 0;
    st.assign(4 * n, {0, 0});
    lazy.assign(4 * n, default_value);
  }
  void relax(int id) {
    st[id].first = min(st[id * 2].first, st[id * 2 | 1].first);
    st[id].second = 0;
    if (st[id].first == st[id * 2].first)
      st[id].second = max(st[id * 2].second, st[id].second);
    if (st[id].first == st[id * 2 | 1].first)
      st[id].second = max(st[id * 2 | 1].second, st[id].second);
  }
  void build(const vector<T> &a) { build(a, 1, 1, n); }
  void build(const vector<T> &a, int id, int l, int r) {
    lazy[id] = 0;
    if (l == r) {
      if (l < a.size()) {
        st[id] = {a[l], l};
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    relax(id);
  }

  void down(int id) {
    if (lazy[id] == 0)
      return;
    st[id * 2].first += lazy[id];
    st[id * 2 | 1].first += lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id * 2 | 1] += lazy[id];
    lazy[id] = 0;
  }
  void update(int u, int v, T val) { update(u, v, val, 1, 1, n); }
  void update(int u, int v, T val, int id, int l, int r) {
    if (v < l || r < u)
      return;
    if (u <= l && r <= v) {
      lazy[id] += val;
      st[id].first += val;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    relax(id);
  }
};

const int N = (int)1e5 + 5;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      d[i] = i - 1;
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      d[v]--;
    }
    vector<int> ans;
    lazySegTree<int> seg(n + 5);
    seg.build(d);
    for (int i = 0; i < n; i++) {
      int u = seg.st[1].second;
      ans.push_back(u);
      seg.update(u + 1, n, -1);
      for (int v : adj[u])
        seg.update(v, v, 1);
      seg.update(u, u, n + 5);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
}
