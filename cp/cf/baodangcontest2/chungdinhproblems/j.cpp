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
#define int long long

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
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

Mint cnt(int bound, int k) {
  bound++;
  int t = (1ll << k);
  Mint ret = ((bound / t) / 2 * t);
  if(((bound / t) & 1)) {
    ret += Mint(Mint(bound) - Mint(Mint(bound / t) * Mint(t)));
  }
  return ret;
}

Mint cnt(int l, int r, int k) {
  // dbg((int)l, (int) r)
  return cnt(r, k) - cnt(l - 1, k);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int q;
  cin >> q;
  while(q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    Mint ans = 0;
    for(int k = 0; k <= 50; k++) {
      if((1ll << k) > max((int) r2, (int) c2)) {
        break;
      }
      Mint curr = 0;
      Mint r = cnt(r1, r2, k);
      Mint c = cnt(c1, c2, k);
      curr += r * (c2 - c1 + 1) + c * (r2 - r1 + 1) - r * c;
      curr *= Mint(1ll << k);
      ans += curr;
    }
    cout << ans << '\n';
  }
}

