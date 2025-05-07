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
    T default_value = 0;
    st.assign(4 * n, default_value);
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
    st[id] = st[id * 2] + st[id * 2 | 1];
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
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return 0;
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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  vector<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s.push_back(a[i]);
  }

  vector<pair<char, pair<int, int>>> que(q);
  for (int i = 0; i < q; i++) {
    char t;
    int x, y;
    cin >> t >> x >> y;
    que[i] = {t, {x, y}};
    s.push_back(y);
    if (t == '?') {
      s.push_back(x);
    }
  }

  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  auto idx = [&] (int val) -> int {
    return lower_bound(s.begin(), s.end(), val) - s.begin() + 1;
  };

  SegTree<int> st(int(s.size()) + 5);
  for (int i = 1; i <= n; i++) {
    st.update(idx(a[i]), 1);
  }

  for (int i = 0; i < q; i++) {
    auto [t, p] = que[i];
    auto [x, y] = p;
    if (t == '!') {
      st.update(idx(a[x]), -1);
      st.update(idx(y), 1);
      a[x] = y;
    } else {
      cout << st.query(idx(x), idx(y)) << '\n';
    }
  }
}

