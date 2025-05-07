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
#define int long long

const int N = (int) 5e4 + 5, INF = (int) 1e18;
vector<int> pre;

// segtree with one-based indexing
//
// build:
//    segtree<int, N> seg; // N is constant
//    seg.build(a); // vector `a` must be one-indexed
// 
// update:
//    seg.update(pos, inc); //increase a[pos] to a[pos] + inc
//    //you may want to set this
// query:
//    seg.query(l, r)

template<class T, int SZ>
struct segTree {
  vector<T> st;
  segTree() {
    T default_value = {INF, -INF};
    st.assign(4 * SZ, default_value);
  }
  int val(T a) const {
    return a[2];
  }
  T combine(T a, T b) {
    return {min(a[0], b[0]), max(a[1], b[1]), max({a[2], b[2], b[1] - a[0]})};
  }
  void build(const vector<int>& a, int id = 1, int l = 1, int r = SZ) {
    if(l == r) {
      if(l < a.size()) {
        st[id] = {pre[l - 1], pre[l], a[l]};
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v, int id = 1, int l = 1, int r = SZ) {
    if(v < l || r < u) {
      return {INF, -INF, -INF};
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    auto q1 = query(u, v, id * 2, l, mid), q2 = query(u, v, id * 2 | 1, mid + 1, r);
    return combine(q1, q2);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  pre.assign(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = a[i] + pre[i - 1];
  }
  segTree<array<int, 3>, N> seg;
  seg.build(a);
  // ofstream ft("gss_sol");
  int m;
  cin >> m;
  while(m--) {
    int l, r;
    cin >> l >> r;
    cout << seg.val(seg.query(l, r)) << '\n';
  }
}

