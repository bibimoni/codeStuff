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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> cnt(n + 1, 0);
    queue<int> q;
    q.push(1);
    cnt[1] = 1;
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (cnt[v]) {
          continue;
        }
        cnt[v] = 1 - cnt[u];
        q.push(v);
      }
    }
    int cntEven = 0;
    for (int u = 1; u <= n; u++) {
      if (cnt[u] == 0) {
        cntEven += 1;
      }
    }
    if (cntEven > n / 2) {
      cout << n - cntEven << '\n';
      for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {
          cout << i << ' ';
        }
      }
    } else {
      cout << cntEven << '\n';
      for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
          cout << i << ' ';
        }
      }
    }
    cout << '\n';
  }
}

