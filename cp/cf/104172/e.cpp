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

template <class T> struct LazySegTree {
  vector<T> st, lazy;
  int n;
  LazySegTree(int _n) : n(_n) {
    T default_value = T();
    st.assign(4 * n + 5, default_value);
  }
  void update(int u, int v, int val) { update(u, v, val, 1, 1, n); }
  void update(int u, int v, int val, int id, int l, int r) {
    if (v < l || r < u)
      return;
    if (u <= l && r <= v) {
      st[id].cnt += val;
      if (st[id].cnt > 0) {
        st[id].len = r - l + 1;
      } else if (id * 2 + 1 < (int)st.size()) {
        st[id].len = st[id * 2].len + st[id * 2 | 1].len;
      } else {
        st[id].len = 0;
      }

      return;
    }
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    if (st[id].cnt == 0 && l < r) {
      st[id].len = st[id * 2].len + st[id * 2 | 1].len;
    }
  }
};

struct Node {
  int cnt, len;
  Node() {}
};
struct Segtree {
  vector<int> st;
  vector<int> lz;
  int n;

private:
  void update(int i, int l, int r, int u, int v, int val) {
    if (u > r || v < l) {
      return;
    }
    if (u <= l && r <= v) {
      lz[i] += val;
      if (lz[i] > 0) {
        dbg(l, r, "all");
        st[i] = r - l + 1;
      } else if (i * 2 + 1 < st.size()) {
        dbg(l, r, st[i * 2], st[i * 2 | 1]);
        st[i] = st[i << 1] + st[i << 1 | 1];
      } else {
        st[i] = 0;
      }
      return;
    }
    int mid = (l + r) >> 1;
    update(i << 1, l, mid, u, v, val);
    update(i << 1 | 1, mid + 1, r, u, v, val);
    if (lz[i] == 0) {
      st[i] = st[i << 1] + st[i << 1 | 1];
    }
  }

public:
  Segtree() {}
  Segtree(int _n) {
    n = _n;
    st.assign(4 * n + 5, 0);
    lz.assign(4 * n + 5, 0);
  }

  int get() { return st[1]; }
  void update(int u, int v, int val) {
    return this->update(1, 1, n, u, v, val);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // int n, k;
  // cin >> n >> k;
  // vector<int> a(n + 1);
  // for (int i = 1; i <= n; i++) {
  //   cin >> a[i];
  // }

  // LazySegTree<Node> st(10);
  // st.update(1, 5, 1);
  // st.update(3, 6, 1);
  // st.update(2, 8, 1);
  // // 1 1 1 1 1 0 0 0 0 0
  // // 1 1 2 2 2 2 0 0 0 0
  // // 1 2 3 3 3 3 3 3 0 0
  // cout << st.st[1].len << '\n';
  // // 0 1 2 2 2 2 2 2 -1 -1
  // st.update(1, 10, -1);
  // cout << st.st[1].len << '\n';
  //
  Segtree st1(10);
  st1.update(1, 5, 1);
  st1.update(3, 6, 1);
  st1.update(2, 8, 1);
  cout << st1.get() << '\n';
  st1.update(1, 10, -1);
  cout << st1.get() << '\n';
}
