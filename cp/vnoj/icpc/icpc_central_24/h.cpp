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

struct LazySegTree {
  int n;
  vector<int> lazy, st, st_max;
  LazySegTree(int _n) : n(_n) {
    lazy.assign(4 * n + 5, 0);
    st.assign(4 * n + 5, 0);
    st_max.assign(4 * n + 5, 0);
  }

  void build(const vector<int> &a) {
    build(a, 1, 1, n);
  }

  void build(const vector<int> &a, int id, int l, int r) {
    if (l == r) {
      if (int(a.size()) > l) {
        st[id] = a[l];
        st_max[id] = a[l];
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2 | 1] + st[id * 2];
    st_max[id] = max(st[id * 2 | 1], st[id * 2]);
  }

  int query_max(int u, int v) {
    return query_max(u, v, 1, 1, n);
  }

  int query_max(int u, int v, int id, int l, int r) {
    if (v < l || r < u) {
      return 0;
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return max(query_max(u, v, id * 2, l, mid), query_max(u, v, id * 2 | 1, mid + 1, r));
  }

  void down(int id) {
    st[id * 2 | 1] += lazy[id];
    st[id * 2] += lazy[id];
    lazy[id * 2 | 1] += lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id] = 0;
  }

  void update_max(int pos, int del) {
    update_max(pos, del, 1, 1, n);
  }

  int find_idx(int val, int l, int r) {
    int lo = l, hi = r, ret = l;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (query_max(l, mid) == val) {
        lo = mid + 1;
        ret = mid;
      } else {
        hi = mid - 1;
      }
    }
    return ret;
  }

  void update_max(int pos, int del, int id, int l, int r) {
    if (r < pos || l > pos) {
      return;
    }
    if (l == r) {
      st_max[id] += del;
      return;
    }
    int mid = (l + r) >> 1;
    update_max(pos, del, id * 2, l, mid);
    update_max(pos, del, id * 2 | 1, mid + 1, r);
    st_max[id] = max(st_max[id * 2], st_max[id * 2 | 1]);
  }

  void update(int u, int v, int del) {
    update(u, v, del, 1, 1, n);
  }

  void update(int u, int v, int del, int id, int l, int r) {
    if (v < l || r < u) {
      return;
    }
    if (u <= l && r <= v) {
      st[id] += del;
      lazy[id] += del;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, del, id * 2, l, mid);
    update(u, v, del, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }

  int query(int u, int v) {
    return query(u, v);
  }

  int query(int u, int v, int id, int l, int r) {
    if (v < l || r < u) {
      return 0;
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    down(id);
    int mid = (l + r) >> 1;
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

struct Fenwick {
  vector<int> ft;
  int n;
  Fenwick(int _n) : n(_n) {
    ft.assign(n + 5, 0);
  }

  void build(const vector<int> &a) {
    for (int i = 1; i < a.size(); i++) {
      update(i, a[i]);
    }
  }

  void update(int id, int del) {
    for (; id <= n; id += id & (-id)) {
      ft[id] += del;
    }
  }

  int query(int id) {
    int ret = 0;
    for (; id > 0; id -= id & (-id)) {
      ret += ft[id];
    }
    return ret;
  }

  int query(int l, int r) {
    int cur = query(r);
    if (l - 1 > 0) {
      cur -= query(l);
    } 
    return cur;
  }
};

template<class T>
struct RMQ {
  vector<vector<T>> st;
  int n;
  int LG;
  void build (const vector<T> &a) {
    LG = 20;
    n = a.size() - 1;
    st = vector<vector<T>>(LG + 1, vector<T>(n + 5));
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T query(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
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
  }
  LazySegTree st(n);
  st.build(a);
  Fenwick ft(n);
  ft.build(a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      ft.update(p, x - a[p]);
      if (p < n) {
        
      }
      a[p] = x;
    } else if (type == 2) {
      int p;
      cin >> p;
    } else if (type == 3) {
      int l, r;
      cin >> l >> r;

    }
  }
}

