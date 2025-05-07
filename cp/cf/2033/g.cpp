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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector lowest(n + 1, pair{0, 0});
    vector h(n + 1, 0);
    auto dfs = [&] (this auto &&self, int u, int p) -> void {
      if (u != p) {
        h[u] = h[p] + 1;
      }
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(v, u);
        if (lowest[u].second < lowest[v].first + 1) {
          lowest[u].second = lowest[v].first + 1;
        }
        if (lowest[u].first < lowest[u].second) {
          swap(lowest[u].first, lowest[u].second);
        }
      }
    };
    dfs(1, 1);

    int logn = __lg(n + 1);
    vector lift = vector(n + 1, vector(logn + 1, pair{0, 0}));
    auto build_lift = [&] (this auto &&self, int u, int p) -> void {
      lift[u][0] = {lowest[p].first, p};
      if (lowest[p].first == lowest[u].first + 1) {
        lift[u][0].first = lowest[p].second; // p go down to the same child u as the child u goes up to p, we change child
      }
      lift[u][0].first -= h[p];
      for (int j = 1; j <= logn; j++) {
        lift[u][j].second = lift[lift[u][j - 1].second][j - 1].second;
        lift[u][j].first = max(lift[u][j - 1].first, lift[lift[u][j - 1].second][j - 1].first);
      }
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(v, u);
      }
    };
    build_lift(1, 1);

    int q;
    cin >> q;
    while (q--) {
      int v, k;
      cin >> v >> k;
      k = min(k, (int)h[v]);
      int ans = lowest[v].first - h[v];
      int ss = h[v];    
      for (int j = logn; j >= 0; j--) {
        if ((1 << j) <= k) {
          k -= (1 << j);
          ans = max(ans, (int)lift[v][j].first);
          v = lift[v][j].second;
        }
      }
      cout << ans + ss << ' ';
    }
    cout<< '\n';
  }
}

