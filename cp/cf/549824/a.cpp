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
 
const int md = 998244353;
 
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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> divs(q + 1);
  for (int i = 1; i <= q; i++) {
    for (int j = i; j <= q; j += i) {
      divs[j] += 1;
    }
  }
  auto exp = [&] (int a, int b) -> int {
    int x = a, res = 1;
    int p = b;
    while (p > 0) {
      dbg(res, divs[x]);
      if (p & 1) (res *= x) %= q;
      (x *= divs[x]) %= q;
      p >>= 1;
    }
    return res;
  };
  for (int i = 0; i < n; i++) {
    cout << exp(a[i], p + 1) << " \n"[i == n - 1];
  }
}


