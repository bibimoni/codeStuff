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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
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
    const int INF = 1e18;
    auto calcDfs = [&](auto &&self, int u, int p, int sign, int val, int mn,
                       vector<int> &ans) -> void {
      val += a[u] * sign;
      mn = min(mn, val);
      ans[u] = val - mn;
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(self, v, u, -sign, val, mn, ans);
      }
    };

    vector<int> ansOdd(n + 1, -INF), ansEven(n + 1, -INF);
    calcDfs(calcDfs, 1, 1, -1, 0, 0, ansOdd);
    calcDfs(calcDfs, 1, 1, 1, 0, 0, ansEven);
    for (int i = 1; i <= n; i++) {
      if (h[i] % 2 == 0) {
        cout << ansEven[i] << " \n"[i == n];
      } else {
        cout << ansOdd[i] << " \n"[i == n];
      }
    }
  }
}
