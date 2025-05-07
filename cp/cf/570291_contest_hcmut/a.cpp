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

// const int N = 3e5 + 5;
const int N = 3e5 + 5;
int n, q;
int a[N];

struct ST {
  pair<int, int> st[4 * N];
  int n;
  pair<int, int> combine(pair<int, int> lhs, pair<int, int> rhs) {
    auto [ans_l, sum_l] = lhs;
    auto [ans_r, sum_r] = rhs;
    if (lhs == pair<int, int>{-1, -1}) {
      return rhs;
    } else if (rhs == pair<int, int>{-1, -1}) {
      return lhs;
    }
    pair<int, int> ret;
    if (ans_l + sum_l >= ans_r) {
      ret.first = ans_l;
    } else {
      ret.first = ans_r - sum_l;
    }
    ret.second = sum_l + sum_r;
    return ret;
  }
  void build(int _n) {
    n = _n;
    build(1, 1, n);
  }
  void build(int id, int l, int r) {
    if (l == r) {
      st[id] = {a[l], a[l]};
      return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 | 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 | 1]);
  }
  void update(int i, int val) {
    update(i, val, 1, 1, n);
  }
  void update(int i, int val, int id, int l, int r) {
    if (r < i || l > i) {
      return;
    }
    if (l == r) {
      st[id] = {val, val};
      return;
    }
    int mid = (l + r) >> 1;
    update(i, val, id * 2, l, mid);
    update(i, val, id * 2 | 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 | 1]);
  }
  pair<int, int> query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  pair<int, int> query(int u, int v, int id, int l, int r) {
    if (r < u || l > v) {
      return pair<int, int>{-1, -1};
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return combine(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("lol.inp", "r", stdin);
  freopen("lol.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ST st;
  st.build(n);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      st.update(i, x);
    } else {
      int u, v;
      cin >> u >> v;
      cout << st.query(u, v).first << '\n';
    }
  }
}


