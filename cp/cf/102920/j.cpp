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

  T &operator^=(const T &p) {
    assert(n == p.n);
    for (int i = 0; i < int(dat.size()); i++) {
      dat[i] ^= p.dat[i];
    }
    return *this;
  }

  T operator^(const T &p) const { return T(*this) ^= p; }

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

vector<Bitsex> inverse(vector<Bitsex> a) {
  int n = int(a.size());
  vector<Bitsex> b(n, Bitsex(n));
  for (int i = 0; i < n; i++) {
    b[i][i] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int k = i + 1; k < n; k++) {
      if (a[k][i]) {
        swap(a[k], a[i]);
        swap(b[k], b[i]);
        break;
      }
    }
    if (!a[i][i]) {
      return {};
    }
    for (int k = 0; k < n; k++) {
      if (i == k) {
        continue;
      }
      if (a[k][i]) {
        a[k] ^= a[i];
        b[k] ^= b[i];
      }
    }
  }
  return b;
}

bool det(vector<Bitsex> a) {
  int n = int(a.size());
  for (int i = 0; i < n; i++) {
    for (int k = i + 1; k < n; k++) {
      if (a[k][i]) {
        swap(a[k], a[i]);
        break;
      }
    }
    if (!a[i][i]) {
      return 0;
    }
    for (int k = i + 1; k < n; k++) {
      if (a[k][i]) {
        a[k] ^= a[i];
      }
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Bitsex> a(n, Bitsex(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      a[j][i] = x;
    }
  }

  auto mul = [&](vector<Bitsex> x, Bitsex y) -> Bitsex {
    Bitsex ans(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans[i] = ans[i] ^ (int(x[i][j]) & int(y[j]));
      }
    }
    return ans;
  };

  vector<Bitsex> inv_a = inverse(a);
  vector<vector<int>> sols;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    Bitsex b(n);
    b[i] = b[i] ^ 1;
    if (inv_a.size() == 0) {
      assert(det(a) == 0);
      ok = false;
      break;
    }
    vector<int> cur;
    Bitsex res = mul(inv_a, b);
    for (int j = 0; j < n; j++) {
      if (res[j] == 1) {
        cur.push_back(j + 1);
      }
    }
    sols.push_back(cur);
  }
  if (ok) {
    for (auto sol : sols) {
      for (int x : sol) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << -1;
  }
}
