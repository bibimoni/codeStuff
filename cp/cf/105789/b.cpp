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
// #define int int64_t

typedef unsigned long long u64;
struct Bitsex {
  using T = Bitsex;
  int n;
  vector<u64> dat;

  Bitsex(int _n = 0, int x = 0) : n(_n) {
    assert(x == 0 || x == 1);
    u64 v = (x == 0 ? 0 : -1);
    dat.assign((n + 63) >> 6, v); // ceil(n / 64)
    if (n) {
      dat.back() >>= (64 * dat.size()) - n;
    }
  }

  int size() { return n; }

  void resize(int size) {
    dat.resize((size + 63) >> 6);
    int rem = size & 63;
    if (rem != 0) {
      u64 mask = (u64(1) << rem) - 1;
      dat.back() &= mask;
    }
    n = size;
  }

  class Proxy {
  private:
    vector<u64> &dat;
    int index;

  public:
    Proxy(vector<u64> &d, int i) : dat(d), index(i) {}
    operator bool() const { return (dat[index >> 6] >> (index & 63)) & 1; }

    Proxy &operator=(u64 value) {
      dat[index >> 6] &= ~(u64(1) << (index & 63));
      dat[index >> 6] |= (value & 1) << (index & 63);
      return *this;
    }
    void flip() { dat[index >> 6] ^= (u64(1) << (index & 63)); }
  };

  Proxy operator[](int i) { return Proxy(dat, i); }

  bool operator==(const T &p) {
    assert(n == p.n);
    for (int i = 0; i < int(dat.size()); i++) {
      if (dat[i] != p.dat[i]) {
        return false;
      }
    }
    return true;
  }

  T &operator|=(const T &p) {
    assert(n == p.n);
    for (int i = 0; i < int(dat.size()); i++) {
      dat[i] |= p.dat[i];
    }
    return *this;
  }
  T &operator&=(const T &p) {
    assert(n == p.n);
    for (int i = 0; i < int(dat.size()); i++) {
      dat[i] &= p.dat[i];
    }
    return *this;
  }
  T &operator^=(const T &p) {
    assert(n == p.n);
    for (int i = 0; i < int(dat.size()); i++) {
      dat[i] ^= p.dat[i];
    }
    return *this;
  }

  T operator^(const T &p) const { return T(*this) ^= p; }
  T operator|(const T &p) const { return T(*this) |= p; }
  T operator&(const T &p) const { return T(*this) &= p; }

  static string TO_STR[256];
  string to_string() const {
    if (TO_STR[0].empty()) {
      precompute();
    }
    string s = "";
    for (auto &x : dat) {
      for (int i = 0; i < 8; i++) {
        s += TO_STR[(x >> (8 * i) & 255)];
      }
    }
    s.resize(n);
    return s;
  }

  static void precompute() {
    for (int i = 0; i < 256; i++) {
      string x;
      for (int j = 0; j < 8; j++) {
        x += '0' + (i >> j & 1);
      }
      TO_STR[i] = x;
    }
  }
};
string Bitsex::TO_STR[256];

// Solve system of linear equations (mod 2)
// Required:
//  - Bitsex
// Time complexity (n^3 / 64)
// Verified:
//  - https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
// Usage:
//  - solve_linear(A, b, w)
// Find the solution (x) and the basis for Ax = b
// The return is an (r + 1) * w matrix containing
// x_1, x_2, ..., x_w (solution)
// d_11, d_12, ..., d_1w - d_1
// ... (basis)
// d_r1, d_r2, ..., d_rw - d_r

// all solutions = x + c_1 * d_1 + c_2 * d_2 + ... + c_r * d_r (c_i : constant)
vector<Bitsex> solve_linear(vector<Bitsex> a, Bitsex b, int w) {
  int h = a.size();
  if (h > 0) {
    assert((int)a[0].size() == w);
  }
  int r = 0;
  for (int c = 0; c < w; c++) {
    if (r == h) {
      break;
    }
    for (int i = r + 1; i < h; i++) {
      if (a[i][c]) {
        swap(a[i], a[r]);
        if (b[r] != b[i]) {
          b[r] = !b[r];
          b[i] = !b[i];
        }
        break;
      }
    }

    if (!a[r][c]) {
      continue;
    }
    for (int i = 0; i < h; i++) {
      if (i != r && a[i][c]) {
        b[i] = b[i] ^ b[r];
        a[i] ^= a[r];
      }
    }

    r += 1;
  }

  for (int i = r; i < h; i++) {
    if (b[i]) {
      return {};
    }
  }

  vector<Bitsex> res(1, Bitsex(w));

  vector<int> pivot(w, -1);
  int p = 0;
  for (int i = 0; i < r; i++) {
    while (!a[i][p]) {
      p += 1;
    }
    res[0][p] = bool(b[i]);
    pivot[p] = i;
  }

  for (int c = 0; c < w; c++) {
    if (pivot[c] == -1) {
      Bitsex x(w);
      x[c] = 1;
      for (int i = 0; i < c; i++) {
        if (pivot[i] != -1 && a[pivot[i]][c]) {
          x[i] = 1;
        }
      }
      res.push_back(x);
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<string> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  vector<Bitsex> a(k + 1, Bitsex(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      a[j][i] = t[i][j] - '0';
    }
  }
  a[k] = Bitsex(n, 1);

  Bitsex b(n);
  auto ans = solve_linear(a, b, n);
  int r = int(ans.size() - 1);
  if (r == 0) {
    cout << "*";
    return 0;
  }
  Bitsex c = ans[1];
  int count = 0;
  for (int i = 0; i < n; i++) {
    count += c[i];
  }
  int tot = count;
  for (int i = 0; i < n; i++) {
    count -= c[i];
    if (c[i] == 1) {
      cout << (count >= tot / 2 ? 1 : 2);
    } else {
      cout << "0";
    }
  }
}
