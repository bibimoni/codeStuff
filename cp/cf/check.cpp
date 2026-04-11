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
  modnum(int v_) : v(v_ % MOD) {
    if (v < 0)
      v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream &operator<<(std::ostream &out, const modnum &n) {
    return out << static_cast<int>(n);
  }
  friend std::istream &operator>>(std::istream &in, modnum &n) {
    int v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum &a, const modnum &b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum &a, const modnum &b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum &m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum &m) { return m.neg(); }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum &operator++() {
    v++;
    if (v == MOD)
      v = 0;
    return *this;
  }
  modnum &operator--() {
    if (v == 0)
      v = MOD;
    v--;
    return *this;
  }
  modnum &operator+=(const modnum &o) {
    v += o.v;
    if (v >= MOD)
      v -= MOD;
    return *this;
  }
  modnum &operator-=(const modnum &o) {
    v -= o.v;
    if (v < 0)
      v += MOD;
    return *this;
  }
  modnum &operator*=(const modnum &o) {
    v = v * o.v % MOD;
    return *this;
  }
  modnum &operator/=(const modnum &o) { return *this *= o.inv(); }
  friend modnum operator+(const modnum &a, const modnum &b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum &a, const modnum &b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum &a, const modnum &b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum &a, const modnum &b) {
    return modnum(a) /= b;
  }
};

const int md = 998244353;

using Mint = modnum<md>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

template <int M, typename U> modnum<M> power(const modnum<M> &a, const U &b) {
  assert(b >= 0);
  modnum<M> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1)
      res *= x;
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
  // while ((int) fact.size() < k + 1) {
  while ((int)fact.size() < n + 1) {
    fact.push_back(fact.back() * (int)fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
  // Mint ret = inv_fact[k];
  // for (int i = 1; i <= k; i++) {
  //   ret *= n - i + 1;
  // }
  // return ret;
}

typedef long double ld;
const ld EPS = 1e-9;
template <typename T> bool isZero(T v) {
  if constexpr (is_same_v<T, ld>) {
    return abs(v) < EPS;
  }
  return v == 0;
}
bool notFound = false;
template <typename T>
vector<vector<T>> solve_linear(vector<vector<T>> &a, vector<T> b, int w) {
  int h = (int)a.size();
  if (h > 0) {
    assert((int)a[0].size() == w);
  }
  int r = 0;
  vector<int> used(w);
  vector<int> idxs;
  for (int c = 0; c < w; c++) {
    int id = -1;
    for (int i = r; i < h; i++) {
      if (!isZero(a[i][c])) {
        id = i;
        break;
      }
    }

    if (id == -1) {
      continue;
    }
    if (r != id) {
      swap(a[r], a[id]);
    }
    swap(b[r], b[id]);

    for (int i = r + 1; i < h; i++) {
      if (isZero(a[i][c])) {
        continue;
      }
      T coeff = a[i][c] / a[r][c];
      for (int j = c; j < w; j++) {
        a[i][j] -= coeff * a[r][j];
      }
      b[i] -= coeff * b[r];
    }

    r += 1;
    used[c] = 1;
    idxs.push_back(c);
    if (r == h) {
      break;
    }
  }
  for (int i = r; i < h; i++) {
    if (!isZero(b[i])) {
      return {};
    }
  }
  vector<vector<T>> sols;
  {
    vector<T> v(w);
    for (int i = r - 1; i >= 0; i--) {
      int f = idxs[i];
      v[f] = b[i];
      for (int j = f + 1; j < w; j++) {
        v[f] -= a[i][j] * v[j];
      }
      v[f] /= a[i][f];
    }
    sols.push_back(v);
  }
  for (int c = 0; c < w; c++) {
    if (used[c]) {
      continue;
    }
    vector<T> v(w);
    v[c] = T(1);
    for (int i = r - 1; i >= 0; i--) {
      int f = idxs[i];
      for (int j = f + 1; j < w; j++) {
        v[f] -= a[i][j] * v[j];
      }
      v[f] /= a[i][f];
    }
    sols.push_back(v);
  }
  return sols;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<ld>> a(n, vector<ld>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }

  vector<ld> b(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[i] = x;
  }
  auto ans = solve_linear(a, b, m);
  if (ans.size() == 0) {
    cout << -1;
  } else {
    cout << ans.size() - 1 << '\n';
    for (auto x : ans) {
      for (auto v : x) {
        cout << v << ' ';
      }
      cout << '\n';
    }
  }
}
