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

const int N = int(1e5 + 5);

template <class T>
struct LazySegTree {
  int st[4 * N];
  pair<int, int> lazy[4 * N];
  int n;
  LazySegTree() {}
  LazySegTree(int _n) : n(_n) {
    T default_value = 0;
    for (int i = 0; i < 4 * N; i++) {
      st[i] = default_value;
      lazy[i] = {default_value, default_value};
    }
  }  
  void down(int id, int l, int r) {
    if(lazy[id].first == 0)
      return;
    int mid = (l + r) >> 1;
    st[id * 2] = lazy[id].second * (mid - l + 1);
    st[id * 2 | 1] = lazy[id].second * (r - mid);
    lazy[id * 2] = lazy[id];
    lazy[id * 2 | 1] = lazy[id];
    lazy[id] = {0, 0};
  }
  void update(int u, int v, T val) {
    update(u, v, val, 1, 1, n);
  }
  void update(int u, int v, T val, int id, int l, int r) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] = {1, val};
      st[id] = val * (r - l + 1);
      return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return int(0);
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("sorting.inp", "r", stdin);
  freopen("sorting.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  const int ALP = 26;
  LazySegTree<int> st[ALP];
  for (int c = 0; c < ALP; c++) {
    st[c] = LazySegTree<int>(n);
    for (int i = 1; i <= n; i++) {
      st[c].update(i, i, int(s[i] - 'a' == c));
    }
  }
  int ch[ALP];
  while (q--) {
    int type, l, r;
    cin >> type;
    cin >> l >> r;
   
    for (int c = 0; c < ALP; c++) {
      ch[c] = st[c].query(l, r);
      st[c].update(l, r, 0);
    }
    if (type == 2) {
      int cur = l;
      for (int c = 0; c < ALP; c++) {
        if (ch[c] != 0) {
          st[c].update(cur, cur + ch[c] - 1, 1);
          cur += ch[c];
        }
      }
    } else {
      int cur = l;
      for (int c = ALP - 1; c >= 0; c--) {
        if (ch[c] != 0) {
          st[c].update(cur, cur + ch[c] - 1, 1);
          cur += ch[c];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int c = 0; c < 26; c++) {
      if (st[c].query(i, i) != 0) {
        cout << char(c + 'a');
        break;
      }
    }
  }
  cout << '\n';
}


