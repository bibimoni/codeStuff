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

/*
  Hash node for hashing modification in segment tree
*/

struct Hash {
  int fwd, bwd, pwr, base, mod;
  bool is_trash;

  Hash() {
    is_trash = true;
  }
  Hash(int _base, int _mod) : base(_base), mod(_mod) {
    fwd = 0, bwd = 0, pwr = base;
    is_trash = false;
  }

  /*
    update a character for this Hash node
    **warning: must be the leaf node**
  */

  void update(char c) {
    fwd = c - 'a';
    bwd = c - 'a';   
    is_trash = false; 
  }

  /*
    This hashing function works like this
      fwd(S) = sum(S[i] * base^(|S| - i)) % mod p (1 <= i <= |S|, base < p)
      bwd(S) = sum(S[i] * base^(i - 1)) % mod p (1 <= i <= |S|, base < p)
    Combine 2 hash
      fwd(S + T) = fwd(S) * T.base + fwd(T)
      bwd(S + T) = bwd(S) + bwd(T) * S.base
  */

  Hash operator+(Hash const& o) {
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

  friend ostream& operator<<(ostream &out, const Hash& o) {
    return out << "[fwd: " << o.fwd << ", bwd: " << o.bwd << ", pwr: " << o.pwr << "]\n";
  }
};

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
  int n, base, mod;
  SegTree() {}
  SegTree(int _n, int _base, int _mod) : n(_n), base(_base), mod(_mod) {
    T default_value = Hash(base, mod);
    st.assign(4 * n + 5, default_value);
  }
  void build(const string &a) {
    build(a, 1, 1, n);
  }
  void build(const string& a, int id, int l, int r) {
    if(l == r) {
      st[id].update(a[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 | 1];
  }
  void update(int pos, char inc) {
    update(pos, inc, 1, 1, n);
  }
  void update(int pos, char inc, int id, int l, int r) {
    if(pos < l || r < pos) {
      return;
    }
    if(l == r) {
      st[id].update(inc);
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
      return Hash();
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    return query(u, v, id * 2, l, mid) + query(u, v, id * 2 | 1, mid + 1, r);
  }
};

const int SZ = 5;
const vector<int> MOD = {
  998244353, int(1e9 + 3), int(1e9 + 7), int(1e9 + 11), int(1e9 + 13)
};
vector<int> BASE(SZ);

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s; s = " " + s;

  for (int i = 0; i < SZ; i++) {
    BASE[i] = rng() % MOD[i];
  }
  // dbg(BASE);
  vector<SegTree<Hash>> st(SZ);
  for (int i = 0; i < SZ; i++) {
    st[i] = SegTree<Hash>(n, BASE[i], MOD[i]);
    st[i].build(s);
  }

  auto update_seg = [&] (int x, char c) -> void {
    for (int i = 0; i < SZ; i++) {
      st[i].update(x, c);
    }
  };

  auto get_seg = [&] (int l, int r) -> bool {
    bool ok = true;
    for (int i = 0; i < SZ; i++) {
      Hash ret = st[i].query(l, r);
      ok &= ret.fwd == ret.bwd;
    }
    return ok;
  };

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      char c;
      cin >> x >> c;
      update_seg(x, c);
    } else {
      int l, r;
      cin >> l >> r;
      cout << (get_seg(l, r) ? "Yes\n" : "No\n");
    }
  }
}

