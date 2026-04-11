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

#define ll long long

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
    T default_value = 0;
    st.assign(4 * n + 5, default_value);
  }
  void reset() { st.assign(4 * n + 5, 0); }
  void build(const vector<T> &a) { build(a, 1, 1, n); }
  void build(const vector<T> &a, int id, int l, int r) {
    if (l == r) {
      st[id] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  void update(int pos, T inc) { update(pos, inc, 1, 1, n); }
  void update(int pos, T inc, int id, int l, int r) {
    if (pos < l || r < pos) {
      return;
    }
    if (l == r) {
      st[id] = max(st[id], inc);
      return;
    }
    int mid = (l + r) >> 1;
    update(pos, inc, id * 2, l, mid);
    update(pos, inc, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) { return query(u, v, 1, 1, n); }
  T query(int u, int v, int id, int l, int r) {
    if (v < l || r < u) {
      return 0;
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return max(query(u, v, id * 2, l, mid),
               query(u, v, id * 2 | 1, mid + 1, r));
  }
};

const ll AI = 1e6 + 5;
const ll N = 2e5 + 5;

ll n, q;
ll a[N];

vector<ll> divisors[AI];
vector<ll> pos[N];

#define ii pair<long long, long long>

vector<ii> vadd[N];
vector<ii> qs[N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i < AI; i++) {
    for (int j = i; j < AI; j += i) {
      divisors[j].push_back(i);
    }
  }

  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (ll i = 1; i <= n; i++) {
    for (ll j : divisors[a[i]]) {
      pos[j].push_back(i);
    }
  }

  SegTree<ll> seg(3 * n);
  for (ll g = 1; g <= n; g++) {
    seg.reset();
    int last = 0;
    for (ll i : pos[g]) {
      ll td = seg.query(1, i + n);
      if (td > 0) {
        vadd[i].push_back({td, g});
      }

      if (last) {
        seg.update(2 * i - last + n, last);
      }

      last = i;
    }
  }

  for (int i = 1; i <= q; i++) {
    ll l, r;
    cin >> l >> r;
    qs[r].push_back({l, i});
  }

  seg.reset();
  vector<ll> res(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    for (ii vx : vadd[i]) {
      seg.update(vx.first, vx.second);
    }

    for (ii vx : qs[i]) {
      res[vx.second] = max(res[vx.second], seg.query(vx.first, i));
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << res[i] << endl;
  }
}
