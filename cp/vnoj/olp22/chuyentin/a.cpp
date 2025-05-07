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
// requires modular library

Mint p = 67;
Mint pinv = p.inv();
vector<Mint> rdx(1, 1), rdxi(1, 1);

map<char, int> M;

bool pre_calc = false;

void pre() {
  int i = 1;
  for (char j = '0'; j <= '9'; j++) M[j] = i++;
  for (char j = 'A'; j <= 'Z'; j++) M[j] = i++;
  for (char j = 'a'; j <= 'z'; j++) M[j] = i++;
}

struct Hash {
  string s;
  int length;
  vector<Mint> pref, suf;

  void fillprefHash() {
    Mint h = 0;
    for (int i = 0; i < length; i++) {
      h = (h + rdx[i] * M[s[i]]);
      pref[i] = h;
    }
  }

  void fillsufHash() {
    Mint h = 0;
    for (int i = 0; i < length; i++) {
      h = (h + rdx[i] * M[s[length - 1 - i]]);
      suf[i] = h;
    }
  }

  Hash() {}

  Hash(string _s) : s(_s){
    if (!pre_calc) {
      pre_calc = 1;
      pre();
    }
    length = sz(s);
    while (sz(rdx) < length) {
      rdx.push_back(rdx.back() * p);
      rdxi.push_back(rdxi.back() * pinv);
    }
    pref.assign(length, 0);
    suf.assign(length, 0);
    fillprefHash();
    fillsufHash();
  }

  Mint fwd (int i, int j) {
    Mint left = (i != 0)? pref[i - 1]: 0;
    Mint right = pref[j];
    Mint h = right - left;
    return h * rdxi[i];
  }

  Mint bwd (int i, int j) {
    swap(i, j);
    i = length - 1 - i;
    j = length - 1 - j;
    Mint left = (i != 0)? suf[i - 1]: 0;
    Mint right = suf[j];
    Mint h = right - left;
    return h * rdxi[i];
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  Hash hashS(s);
  int tt;
  cin >> tt;
  while(tt--) {
    int k; cin >> k;
    int l[k];
    for(int &i : l) cin >> i;
    sort(l, l + k, greater<int>());
    int cnt = 0;
    //fenwick<int> ft(n);
    for(int len : l) {
      //dbg(len);
      for(int i = 0; i + len - 1 < n; i++) {
        //if(ft.range(i + 1, i + len) != 0) continue;
        if(hashS.fwd(i, i + len - 1) == hashS.bwd(i, i + len - 1)) {
          cnt++;
          //ft.update(i + 1, 1);
          //ft.update(i + len + 1, -1);
          // dbg(i, i + len - 1, len);
          break;
        }
      }
    }
    cout << (cnt == k ? "YES\n" : "NO\n");
  }
}

