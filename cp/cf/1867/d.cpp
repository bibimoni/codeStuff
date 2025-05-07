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
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i]; 
      adj[i].push_back(b[i]);
    }
    bool ok = true;
    if (k == 1) {
      for (int i = 1; i <= n; i++) {
        if (b[i] != i) {
          ok = false;
        }
      }
      cout << (ok ? "YES\n" : "NO\n");
      continue;
    }
    vector<int> was(n + 1, 0);
    vector<int> p(n + 1, -1);
    int cs = -1, ce = -1;
    auto dfs = [&] (auto &&self, int u) -> bool {
      int sz = 0;
      was[u] = 1;
      for (int v : adj[u]) {
        if (v == p[u]) {
          continue;
        }
        if (was[v] == 1) {
          ce = u;
          cs = v;
          return true;
        } else if (!was[v]) {
          p[v] = u;
          if (self(self, v)) {
            return true;
          }
        }
      }
      was[u] = 2;
      return false;
    };
    for (int i = 1; i <= n; i++) {
      if (!was[i]) {
        if (!dfs(dfs, i)) {
          ok = false;
        } else if (cs != -1 && ce != -1) {
          if (cs == ce) {
            ok = false;
            break;
          }
          int cnt = 1;
          int u = ce;
          while(u != cs) {
            cnt += 1;
            u = p[u];
          }
          if (cnt != k) {
            ok = false;
          }
          cs = -1;
          ce = -1;
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
