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
  vector<T> st;
  vector<pair<int, int>> lazy;
  vector<int> a;
  int n;
  LazySegTree(int _n, vector<int> _a) : a(_a), n(_n) {
    T default_value = 0;
    st.assign(4 * n + 5, default_value);
    lazy.assign(4 * n + 5, {default_value, default_value});
  }  
  pair<int, int> add(pair<int, int> i, pair<int, int> j) {
    return pair<int, int>{i.first + j.first, i.second + j.second};
  }
  void down(int id, int l, int r) {
    if(lazy[id] == pair<int, int>{0, 0})
      return;
    int mid = (l + r) >> 1;
    st[id * 2] += lazy[id].second * (a[mid] - a[l - 1]) - (lazy[id].first) * (mid - l + 1);
    st[id * 2 | 1] += lazy[id].second * (a[r] - a[mid]) - (lazy[id].first) * (r - mid);
    lazy[id * 2] = add(lazy[id * 2], lazy[id]);
    lazy[id * 2 | 1] = add(lazy[id * 2 | 1], lazy[id]);
    lazy[id] = pair<int, int>{0, 0};
  }
  void update(int u, int v) {
    update(u, v, u - 1, 1, 1, n); // bound = u - 1
  }
  void update(int u, int v, int bound, int id, int l, int r) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id].first += bound;
      lazy[id].second += 1;
      st[id] += a[r] - a[l - 1] - (r - l + 1) * bound;
      return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update(u, v, bound, id * 2, l, mid);
    update(u, v, bound, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return T{0};
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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), int(0));
  for (int i = 1; i <= n; i++) {
    p[i] += p[i - 1];
  }
  LazySegTree<int> st(n, p);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      st.update(l, r);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r) + a[r] - a[l - 1] << '\n';
    }
  }
}

