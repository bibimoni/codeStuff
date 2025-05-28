#include <bits/stdc++.h>
using namespace std;
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

const int md = 1e9 + 7;

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

/**
 * Description: Finding LCA and Kth Ancestor using Binary Lifting
 * Caution:
 *    * adj must be one-indexed
 *    * root must be 1 (can be modified if required)
 * Source : https://oj.vnoi.info/submission/4618381
 * Verification : https://oj.vnoi.info/problem/hbtlca
 *
 * usage LCA lca(n + 1, adj, root) // default root is 1
 */

struct LCA {
  vector<vector<int>> par;
  vector<vector<int>> adj;
  vector<int> dep;
  int LG;
  void dfs(int u, int p = 0) {
    par[u][0] = p;
    for (int i = 1; i < LG; i++)
      par[u][i] = par[par[u][i - 1]][i - 1];
    for (int v : adj[u]) {
      if (v == p)
        continue;
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }

  int ancestor(int u, int k) {
    for (int i = 0; i < LG; i++)
      if (k & (1 << i))
        u = par[u][i];
    return u;
  }

  int lca(int u, int v) {
    if (dep[u] < dep[v])
      swap(u, v);
    u = ancestor(u, dep[u] - dep[v]);
    if (u == v)
      return u;
    for (int i = LG - 1; i >= 0; i--)
      if (par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];
  }

  LCA(int _n, vector<vector<int>> &adj, int root = 1) : adj(adj) {
    int n = _n;
    LG = 64 - __builtin_clzll(n);
    par.assign(n, vector<int>(LG, 0));
    dep.assign(n, 0);
    dfs(root);
  }
};

#ifdef int
#undef int
#endif

class Solution {
public:
  vector<int> assignEdgeWeights(vector<vector<int>> &e,
                                vector<vector<int>> &que) {
    int n = e.size() + 1;
    vector<vector<int64_t>> adj(n + 1);
    for (auto p : e) {
      adj[p[0]].push_back(p[1]);
      adj[p[1]].push_back(p[0]);
    }

    vector<int> h(n + 1);
    auto dfs = [&](auto &&self, int u, int p) -> void {
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        h[v] = h[u] + 1;
        self(self, v, u);
      }
    };

    dfs(dfs, 1, 1);
    LCA lc(n + 1, adj, 1);
    vector<int> ans;
    for (auto p : que) {
      int u = p[0], v = p[1];
      int lca = lc.lca(u, v);
      int len = h[u] + h[v] - 2 * h[lca];
      if (len == 0) {
        ans.push_back(0);
      } else {
        ans.push_back((int64_t)power(Mint(2), len - 1));
      }
    }
    return ans;
  }
};
