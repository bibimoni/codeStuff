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

/*
  Hash node for hashing modification in segment tree
*/
struct Hash {
  int fwd, pwr, base, mod;
  bool is_trash;
  
  Hash() {
    is_trash = true;
  }
  Hash(int _base, int _mod) : base(_base), mod(_mod) {
    fwd = 0, pwr = base;
    is_trash = false;
  }
  int convert(char c) {
    if ('0' <= c && c <= '9') {
      return c - '0';
    } else if ('a' <= c && c <= 'z') {
      return c - 'a';
    } else {
      return c - 'A';
    }
  }
  /*
    update a character for this Hash node
    **warning: must be the leaf node**
  */
  void update(char c) {
    fwd = convert(c);
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
  Hash operator+(Hash const& o) {
    if (is_trash) {
      return o;
    } else if (o.is_trash) {
      return *this;
    }
    Hash ret = Hash(base, mod);
    ret.fwd = (o.pwr * fwd + o.fwd) % mod;
    ret.pwr = (pwr * o.pwr) % mod;
    return ret;
  }

  friend ostream& operator<<(ostream &out, const Hash& o) {
    return out << "[fwd: " << o.fwd << ", pwr: " << o.pwr << "]\n";
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
  int n;
  SegTree() {}
  SegTree(int _n, int _mod, int _base) : n(_n) {
    T default_value = Hash(_mod, _base);
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

const int SZ = 2;
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
  for (int i = 0; i < SZ; i++) {
    BASE[i] = rng() % MOD[i];
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    map<array<int, SZ>, int> cnt;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] = " " + a[i];
    } 

    auto get_col = [&] (int col) -> string {
      string ret = "";
      for (int i = 1; i <= n; i++) {
        ret += a[i][col];
      }
      return ret;
    };

    vector hashes(m + 1, vector(SZ, SegTree<Hash>()));
    for (int j = 1; j <= m; j++) {
      string cur_col = " " + get_col(j);
      for (int k = 0; k < SZ; k++) {
        hashes[j][k] = SegTree<Hash>(n, MOD[k], BASE[k]);
        hashes[j][k].build(cur_col);
      }
    }

    auto get_hash_after_flip = [&] (int i, int j) -> array<int, SZ> {
      array<int, SZ> ret;
      for (int k = 0; k < SZ; k++) {
        hashes[j][k].update(i, char(1 - a[i][j] + 2 * '0'));
        ret[k] = hashes[j][k].query(1, n).fwd;
        hashes[j][k].update(i, a[i][j]);
      }
      return ret;
    };

    for (int j = 1; j <= m; j++) {
      for (int i = 1; i <= n; i++) {
        array<int, SZ> cur = get_hash_after_flip(i, j);
        cnt[cur] += 1;
      }
    }

    pair<array<int, SZ>, int> mx;
    mx.second = -1; // init
    for (auto [hh, cc] : cnt) {
      if (mx.second < cc) {
        mx.first = hh;
        mx.second = cc;
      }
    }

    assert(mx.second != -1);
    string ans = "";
    for (int j = 1; j <= m; j++) {
      if (ans.size() != 0) {
        break;
      }
      for (int i = 1; i <= n; i++) {
        array<int, SZ> cur = get_hash_after_flip(i, j);
        if (cur == mx.first) {
          ans = get_col(j);
          ans[i - 1] = char(1 - ans[i - 1] + 2 * '0');
          break;
        }
      }
    }
    cout << mx.second << '\n' << ans << '\n';
  }
}


