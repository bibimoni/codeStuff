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

/*
  Hash node for hashing modification in segment tree
*/
struct Hash {
  int fwd, bwd, pwr, base, mod;
  bool is_trash;

  Hash() { is_trash = true; }
  Hash(int _base, int _mod) : base(_base), mod(_mod) {
    fwd = 0, bwd = 0, pwr = base;
    is_trash = false;
  }
  Hash(int _base, int _mod, int _c) : base(_base), mod(_mod) {
    fwd = _c, bwd = _c, pwr = base;
    is_trash = false;
  }
  // int convert(char c) {
  //   if ('0' <= c && c <= '9') {
  //     return c - '0';
  //   } else if ('a' <= c && c <= 'z') {
  //     return c - 'a';
  //   } else {
  //     return c - 'A';
  //   }
  // }
  /*
    update a character for this Hash node
    **warning: must be the leaf node**
  */
  void update(int c) {
    fwd = c;
    bwd = c;
    is_trash = false;
  }

  /*
    This hashing function works like this
      fwd(S) = sum(S[i] * base^(|S| - i)) % mod p (1 <= i <= |S|, base < p)
      bwd(S) = sum(S[i] * base^(i - 1)) % mod p (1 <= i <= |S|, base < p)
    Combine 2 hash
      fwd(S + T) = fwd(S) * T.base + fwd(T)
      bwd(S + T) = bwd(S) + bwd(T) * S.base
    Query a hash
      fwd(S[a..b]) = fwd(S[1..b]) - fwd(S[1..a-1]) * base^(b - a + 1)
  */
  Hash operator+(Hash const &o) {
    if (is_trash) {
      return o;
    } else if (o.is_trash) {
      return *this;
    }
    Hash ret = Hash(base, mod);
    ret.fwd = (o.pwr * fwd + o.fwd) % mod;
    ret.bwd = (bwd + pwr * o.bwd) % mod;
    ret.pwr = (pwr * o.pwr) % mod;
    return ret;
  }

  friend ostream &operator<<(ostream &out, const Hash &o) {
    return out << "[fwd: " << o.fwd << ", bwd: " << o.bwd << ", pwr: " << o.pwr
               << "]\n";
  }
};

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

template <class T> struct LazySegTree {
  vector<T> st, lazy;
  int n;
  LazySegTree(int _n) : n(_n) {
    T default_value = T();
    st.assign(4 * n + 5, default_value);
    lazy.assign(4 * n + 5, default_value);
  }
  void down(int id) {
    if (lazy[id] == 0)
      return;
    st[id * 2] += lazy[id];
    st[id * 2 | 1] += lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id * 2 | 1] += lazy[id];
    lazy[id] = 0;
  }
  void update(int u, int v, T val) { update(u, v, val, 1, 1, n); }
  void update(int u, int v, T val, int id, int l, int r) {
    if (v < l || r < u)
      return;
    if (u <= l && r <= v) {
      lazy[id] = val;
      st[id] = val;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) { return query(u, v, 1, 1, n); }
  T query(int u, int v, int id, int l, int r) {
    if (v < l || r < u) {
      return T();
    }
    if (u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id);
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q, k, b;
  cin >> n >> q >> k >> b;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> ll(n + 1);
  vector<int> rr(n + 1);
  for (int i = 1; i <= n; i++) {
    ll[i] = 2 * a[i] - i * k;
    rr[i] = 2 * a[i] - i * k + 2 * b;
  }

  const int mod1 = int(1e9 + 7);
  const int mod2 = int(1e9 + 3);
  const int base1 = 31;
  const int base2 = 331;
  LazySegTree<Hash> sll1(n);
  LazySegTree<Hash> sll2(n);
  LazySegTree<Hash> srr1(n);
  LazySegTree<Hash> srr2(n);
  for (int i = 1; i <= n; i++) {
    sll1.update(i, i, Hash(mod1, base1, ll[i]));
    sll2.update(i, i, Hash(mod2, base2, ll[i]));
    srr1.update(i, i, Hash(mod1, base1, rr[i]));
    srr2.update(i, i, Hash(mod2, base2, rr[i]));
  }

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, v;
      cin >> l >> r >> v;

    } else {
    }
  }
}
