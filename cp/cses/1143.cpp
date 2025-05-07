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
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  void query(int val) {
    return query(val, 1, 1, n);
  }
  void query(int val, int id, int l, int r) {
    if(l == r) {
      st[id] -= val;
      cout << l << ' ';
    } else {
      int mid = (l + r) >> 1;
      if (st[id * 2] >= val) {
        query(val, id * 2, l, mid);
      } else {
        query(val, id * 2 | 1, mid + 1, r);
      }
      st[id] = max(st[id * 2], st[id * 2 | 1]);
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  SegTree<int> st(n);
  st.build(a);
  while (m--) {
    int x;
    cin >> x;
    if (st.st[1] < x) {
      cout << "0\n";
    } else {
      st.query(x);
    }
  }
}

