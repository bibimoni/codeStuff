/**
 * Author: distiled
 */
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int long long
#define sz(_x) (_x).size()

template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");
private:
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : m - minv(m, a) * m / a;
  }
public:
  modnum() : v(0) {}
  modnum(int v_) : v(v_ % MOD) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << static_cast<int>(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { int v_; in >> v_; n = modnum(v_); return in; }
  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }
  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = v * o.v % MOD;
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

const int md = 1e3 + 7;

using Mint = modnum<md>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

template<int M, typename U>
modnum<M> power(const modnum<M>& a, const U& b) {
  assert(b >= 0);
  modnum<M> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

/**
 * Description: Matrices with binary exponentiation utility
 */

template <class T>
struct matrix {
  vector<vector<T>> a;
  int n, m;

  matrix() {}

  matrix(int _n, int _m) : n(_n), m(_m) {
    a = vector<vector<T>>(n, vector<T>(m));
  }

  matrix(int _n, int _m, T val) : n(_n), m(_m) {
    a = vector<vector<T>>(n, vector<T>(m, val));
  }

  matrix(const vector<T>& oth) {
    a = vector<vector<T>>(sz(oth), vector<T>(1));
    n = sz(oth);
    m = 1;
    for (int i = 0; i < sz(oth); i++) {
      a[i][0] = oth[i];
    }
  }

  matrix(const vector<vector<T>>& oth) {
    a = oth;
    n = sz(a);
    m = sz(a[0]);
  }

  matrix operator*(const matrix& oth) const {
    assert(m == oth.n);
    matrix r(n, oth.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < oth.m; j++) {
        for (int k = 0; k < m; k++) {
          r.a[i][j] += a[i][k] * oth.a[k][j];
        }
      }
    }
    return r;
  }

  matrix& operator*=(const matrix& oth) {
    *this = (*this) * oth;
    return *this;
  }

  template<class U> friend matrix power(const matrix& a, const U& b) {
    assert(b >= 0);
    assert(a.n == a.m);
    matrix x = a;
    matrix res(a.n, a.m);
    for (int i = 0; i < a.n; i++) res.a[i][i] = 1;
    U p = b;
    while (p > 0) {
      if (p & 1) res *= x;
      x *= x;
      p >>= 1;
    }
    return res;
  }

  friend string to_string(matrix M) {
    int mx = 0;
    for (int i = 0; i < M.n; i++) {
      for (int j = 0; j < M.m; j++) {
        mx = max(mx, sz(to_string(M.a[i][j])));
      }
    }
    string res = "";
    for (int i = 0; i < M.n; i++) {
      res += "\n[";
      for (int j = 0; j < M.m; j++) {
        if (j) {
          res += ", ";
        }
        string cur = to_string(M.a[i][j]);
        res += string(mx - sz(cur), ' ') + cur;
      }
      res += "]";
    }
    return res;
  }
};

// lazy_segtree with one-based indexing
// `SZ` must be a power of 2
//
// build:
//    lazy_segtree<int, (1 << 18)> seg;
//    seg.build(a); // vector `a` must be zero-indexed
// 
// update:
//    seg.update(l, r, inc);
//
// query:
//    seg.query(l, r)

template <class T, int SZ>
class lazy_segtree {
  vector<T> t;
  vector<T> lazy;

  void push(int v, int tl, int tr) {
    if (tl != tr) { // check pushing
      lazy[v << 1] += lazy[v];
      lazy[v << 1 | 1] += lazy[v];
    }
    t[v] += (tr - tl + 1) * lazy[v]; // check node update
    lazy[v] = 0; // reset to default
  }

  void pull(int v) {
    t[v] = t[v << 1] + t[v << 1 | 1]; // check pulling
  }

public:
  lazy_segtree() {
    T default_val_t = 0; // check tree default value
    T default_val_l = 0; // check lazy default value

    t.assign(SZ << 1, default_val_t);
    lazy.assign(SZ << 1, default_val_l);
  }

  void build(const vector<T>& a) {
    assert(sz(a) <= SZ);
    for (int i = 0; i < sz(a) - 1; i++) {
      t[SZ + i] = a[i + 1];
    }
    for (int i = SZ - 1; i >= 1; i--) {
      pull(i);
    }
  }

  void update(int l, int r, T inc, int v = 1, int tl = 1, int tr = SZ) {
    push(v, tl, tr);
    if (l > tr || r < tl) return;
    if (l <= tl && tr <= r) {
      lazy[v] += inc; // check update rule
      push(v, tl, tr);
    } else {
      int tm = (tl + tr) >> 1;
      update(l, r, inc, v << 1, tl, tm);
      update(l, r, inc, v << 1 | 1, tm + 1, tr);
      pull(v);
    }
  }

  T query(int l, int r, int v = 1, int tl = 1, int tr = SZ) {
    push(v, tl, tr);
    if (l > tr || r < tl) return 0; // check out-of-index value
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    // check query merging
    return query(l, r, v << 1, tl, tm) + query(l, r, v << 1 | 1, tm + 1, tr);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  auto getFibo = [&] (int k) {
    k--;
    matrix<Mint> base({{1, 0}, {1, 0}}), mul({{1, 1}, {1, 0}});
    for(; k > 0; k /= 2, mul = mul * mul) {
      if(k & 1) base *= mul;
    }
    return base.a[1][0];
  };
  int n, q; cin >> n >> q;
  vector<int> a(n + 1, 0);
  lazy_segtree<int, (1 << 18)> seg;
  seg.build(a);
  while(q--) {
    int type; cin >> type; 
    if(type == 1) {
      int l, r, k; 
      cin >> l >> r >> k;
      seg.update(l, r, (int) getFibo(k));
    }
    if(type == 2) {
      int l, r; cin >> l >> r;
      cout << seg.query(l, r) << '\n';
    }
  }
}
  
