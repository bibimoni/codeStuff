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
    string s;
    cin >> s;
    s = " " + s;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> adj2(n + 1);
    vector<int> deg(n + 1);
    vector<int> deg2(n + 1);
    for (int i = 1; i < n; i++) {
      if (s[i] == 'L') {
        adj[i + 1].push_back(i);
        adj2[i].push_back(i + 1);
        deg[i] += 1;
        deg2[i + 1] += 1;
      } else {
        adj[i].push_back(i + 1);
        adj2[i + 1].push_back(i);
        deg[i + 1] += 1;
        deg2[i] += 1;
      }
    }

    vector<int> cands;
    vector<int> cands2;
    for (int i = 1; i <= n; i++) {
      if (deg[i] == 0) {
        cands.push_back(i);
      }
      if (deg2[i] == 0) {
        cands2.push_back(i);
      }
    }

    vector<int> was(n + 1);
    vector<int> d(n + 1);
    auto dfs = [&](auto &&self, int u, int p) -> void {
      was[u] = 1;
      d[u] += 1;
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        if (!was[v]) {
          self(self, v, u);
        }
        d[u] += d[v];
      }
    };
    for (int v : cands) {
      if (!was[v])
        dfs(dfs, v, v);
    }

    vector<int> was2(n + 1);
    vector<int> d2(n + 1);
    auto dfs2 = [&](auto &&self, int u, int p) -> void {
      was2[u] = 1;
      d2[u] += 1;
      for (int v : adj2[u]) {
        if (v == p) {
          continue;
        }
        if (!was2[v]) {
          self(self, v, u);
        }
        d2[u] += d2[v];
      }
    };
    for (int v : cands2) {
      if (!was2[v])
        dfs2(dfs2, v, v);
    }

    vector<int> c(n + 2);
    for (int i = 1; i <= n; i++) {
      int st = d2[i], ed = n - d[i] + 1;
      c[st] += 1;
      c[ed + 1] -= 1;
    }
    for (int i = 1; i <= n; i++) {
      c[i] += c[i - 1];
      cout << c[i] << " \n"[i == n];
    }
  }
}
