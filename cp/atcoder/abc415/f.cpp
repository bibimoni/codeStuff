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
#define int int64_t

struct Node {
  int left, right, ans;
  int sz;

  char l, r;
  Node() {
    left = -1;
    right = -1;
    ans = -1;
    sz = -1;
    l = '*';
    r = '*';
  }
};

Node combine(Node a, Node b) {
  if (a.sz == -1) {
    return b;
  } else if (b.sz == -1) {
    return a;
  }
  Node ret;
  ret.ans = max(a.ans, b.ans);
  if (a.r == b.l) {
    ret.ans = max(ret.ans, a.right + b.left);
  }
  ret.ans = max({ret.ans, a.left, b.right});
  if (a.left == a.sz && a.l == b.l) {
    ret.left = a.left + b.left;
  } else {
    ret.left = a.left;
  }
  if (b.right == b.sz && b.r == a.r) {
    ret.right = b.right + a.right;
  } else {
    ret.right = b.right;
  }
  ret.l = a.l;
  ret.r = b.r;
  ret.sz = a.sz + b.sz;
  ret.ans = max({ret.ans, ret.left, ret.right});
  return ret;
}
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

template <class T> struct SegTree {
  vector<T> st;
  int n;
  SegTree(int _n) : n(_n) {
    Node tmp;
    T default_value = tmp;
    st.assign(4 * n + 5, default_value);
  }
  void build(const vector<char> &a) { build(a, 1, 1, n); }
  void build(const vector<char> &a, int id, int l, int r) {
    if (l == r) {
      st[id].left = 1;
      st[id].right = 1;
      st[id].ans = 1;
      st[id].l = a[l];
      st[id].r = a[l];
      st[id].sz = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    // st[id] = st[id * 2] + st[id * 2 | 1];
    st[id] = combine(st[id * 2], st[id * 2 | 1]);
  }
  void update(int pos, char inc) { update(pos, inc, 1, 1, n); }
  void update(int pos, char inc, int id, int l, int r) {
    if (pos < l || r < pos) {
      return;
    }
    if (l == r) {
      st[id].left = 1;
      st[id].right = 1;
      st[id].ans = 1;
      st[id].l = inc;
      st[id].r = inc;
      st[id].sz = 1;
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    // st[id] = st[id * 2] + st[id * 2 | 1];
    st[id] = combine(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) { return query(u, v, 1, 1, n); }
  T query(int u, int v, int id, int l, int r) {
    Node ret;
    if (v < l || r < u) {
      return ret;
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return combine(query(u, v, id * 2, l, mid),
                   query(u, v, id * 2 | 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<char> ss(n + 1);
  for (int i = 0; i < n; i++) {
    ss[i + 1] = s[i];
  }
  SegTree<Node> st(n);
  st.build(ss);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i;
      char x;
      cin >> i >> x;
      st.update(i, x);
    } else {
      int l, r;
      cin >> l >> r;
      Node ans = st.query(l, r);
      cout << ans.ans << '\n';
    }
  }
}
