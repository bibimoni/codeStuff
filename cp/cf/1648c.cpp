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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

template <class T, class U = null_type, class cmp = less<T>>
using ordered_set = tree<T, U, cmp, rb_tree_tag,tree_order_statistics_node_update>;

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

/// *** Needs C++11 or C++14 ***/

/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in long long

struct Treap { /// hash = 96814
  int len;
  const int ADD = 1000010;
  const int MAXVAL = 1000000010;
  map<long long, int> mp; /// Change to int if only int in treap
  tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

  Treap(){
    len = 0;
    T.clear(), mp.clear();
  }

  inline void clear(){
    len = 0;
    T.clear(), mp.clear();
  }

  inline void insert(long long x){
    len++, x += MAXVAL;
    int c = mp[x]++;
    T.insert((x * ADD) + c);
  }

  inline void erase(long long x){
    x += MAXVAL;
    int c = mp[x];
    if (c){
      c--, mp[x]--, len--;
      T.erase((x * ADD) + c);
    }
  }

  /// 1-based index, returns the K'th element in the treap, -1 if none exists
  inline long long kth(int k){
    if (k < 1 || k > len) return -1;
    auto it = T.find_by_order(--k);
    return ((*it) / ADD) - MAXVAL;
  }

  /// Count of value < x in treap
  inline int count(long long x){
    x += MAXVAL;
    int c = mp[--x];
    return (T.order_of_key((x * ADD) + c));
  }

  /// Number of elements in treap
  inline int size(){
    return len;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  Treap treap;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    treap.insert(a[i]);
  }
  vector<int> b(m);
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  auto f = [&] (int num) -> Mint {
    while((int) fact.size() < num + 1) { 
      fact.push_back(fact.back() * (int) fact.size());
      inv_fact.push_back(1 / fact.back());
    }
    return fact[num];
  };
  Mint ans = 0;
  sort(a.begin(), a.end());
  for(int i = 0; i < min(n, m); i++) {
    int id = treap.count(b[i]);
    dbg(id);
    ans += f(treap.size() - 1) * id;
    dbg((int) ans);
    treap.erase(b[i]);
  }
  cout << ans << '\n';
  
}

