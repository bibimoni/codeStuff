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
#define int            long long
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
 
const int md = 1e9 + 7;
 
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
  k = min(k, n - k);
  while ((int) fact.size() < k + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  Mint ret = inv_fact[k];
  for (int i = 1; i <= k; i++) {
    ret *= n - i + 1;
  }
  return ret;
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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int n;
  cin >> n;
  if(n == 0) {
    cout << b;
    return 0;
  }
  if(n == 1) {
    cout << a;
    return 0;
  }
  vector<vector<int>> t = {{a, 0, 0, 0}, {b, 0, 0, 0}, {c, 0, 0, 0}, {d, 0, 0, 0}};
  matrix<int> base(t), mul({{3, 2, 2, 3}, {1, 0, 0, 0}, {0, 0, 1, 2}, {0, 0, 1, 0}});
  base = power(mul, n - 1) * base;
  cout << base.a[0][0];
}


