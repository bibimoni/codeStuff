// time-limit: 3000
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    vector<int> p(n + 1);
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
      cin >> p[i];
      adj[i].push_back(p[i]);
      adj[p[i]].push_back(i);
    }
    auto dfs = [&] (auto &&self, int u) -> int {
      int mn = int(1e18);
      bool isleaf = true;
      for (int v : adj[u]) {
        if (v == p[u]) {
          continue;
        }
        isleaf = false;
        int val = self(self, v);
        if (a[u] <= val) {
          val = (val + a[u]) / 2;
        }
        mn = min(mn, val);
      }
      if (isleaf) {
        return a[u];
      }
      return mn;
    };
    int mn = int(1e9);
    for (int v : adj[1]) {
      if (p[1] == v) {
        continue;
      }
      mn = min(mn, dfs(dfs, v));
    }
    cout << mn + a[1] << '\n';
  }
}


