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

const int MOD = (int) 1e9 + 7;

struct Dsu {
  vector<int> par, sz;

public: 
  Dsu() {}

  Dsu (int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    sz.assign(n, 1);
  }

  int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      return false;
    } else {
      if (sz[u] < sz[v]) {
        swap(u, v);
      }
      sz[u] += sz[v];
      par[v] = u;
      return true;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<int> h(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  Dsu dsu_t(n + 1), _dsu_t(n + 1);
  vector<vector<int>> g_t(n + 1), _g_t(n + 1);  
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    if (h[u] > t || h[v] > t) {
      continue;
    }
    g_t[u].push_back(v);
    g_t[v].push_back(u);
    dsu_t.unite(u, v);

    if (h[u] == t || h[v] == t) {
      continue;
    }

    _g_t[u].push_back(v);
    _g_t[v].push_back(u);
    _dsu_t.unite(u, v);
  }
  
  vector<int> sz_t(n + 1, 0), _sz_t(n + 1, 0);
  auto dfs = [&] (auto &&self, vector<vector<int>> &adj, vector<int> &sz, int com_sz, int u, int p) -> int {
    sz[u] = 1;
    int ret = 0;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      (ret += self(self, adj, sz, com_sz, v, u)) %= MOD;
      sz[u] += sz[v];
    }
    (ret += ((((com_sz - sz[u] + MOD) % MOD) * (sz[u] % MOD) % MOD) * (com_sz - 2) % MOD)) %= MOD;
    return ret;
  };

  int f_k = 0;
  for (int i = 1; i <= n; i++) {
    if (dsu_t.find(i) == i) {
      int add = dfs(dfs, g_t, sz_t, dsu_t.sz[i], i, i);
      (f_k += add) %= MOD;
    }
  }

  int _f_k = 0;
  for (int i = 1; i <= n; i++) {
    if (_dsu_t.find(i) == i) {
      int add = dfs(dfs, _g_t, _sz_t, _dsu_t.sz[i], i, i);
      (_f_k += add) %= MOD;
    }
  }
  cout << (f_k - _f_k + MOD) % MOD << '\n';

}

