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
#define sz(_x) (_x).size()

/**
 * Description: Finding centroid of subtree rooted at each vertex in O(N)
 * Source: self
 * Verification: https://codeforces.com/contest/685/submission/102991554
 */

struct Centroid {
  vector<vector<int>> g;
  vector<int> c, dp, mx, pr;

  void Dfs(int u, int p) {
    pr[u] = p;
    dp[u] = 1;
    for (int v : g[u]) {
      if (v == p) continue;
      Dfs(v, u);
      dp[u] += dp[v];
      mx[u] = max(mx[u], dp[v]);
    }
  }

  bool Ask(int u, int v) {
    return ((dp[u] - dp[v]) * 2 <= dp[u] && mx[v] * 2 <= dp[u]);
  }

  void Solve (int u) {
    if (sz(g[u]) == 0) { // Change to sz(g[u]) == 1 if the tree is not given as directed tree
      c[u] = u;
      return;
    }
    int lol = -1;
    for (int v : g[u]) {
      if (v == pr[u]) continue;
      Solve(v);
      if ((lol == -1) || (dp[lol] < dp[v])) {
        lol = v;
      }
    }
    int ce = c[lol];
    while (!Ask(u, ce)) ce = pr[ce];
    c[u] = ce;
  }

  vector<int> get() {
    Dfs(1, 1);
    Solve(1);
    return c;
  }

  Centroid(const vector<vector<int>> g_) : g(g_) {
    int n = sz(g);
    c.resize(n);
    dp.resize(n);
    mx.resize(n);
    pr.assign(n, -1);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> p(n + 1);
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    adj[i].push_back(p[i]);
    adj[p[i]].push_back(i);
  }
  Centroid centroid(adj);
  vector<int> c = centroid.get();
  while (q--) {
    int v;
    cin >> v;
    cout << c[v] << '\n';
  }
}

