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
  int n, m, A, B, C;
  cin >> n >> m >> A >> B >> C;
  vector<int> a(n);
  int tot = 0;
  vector<int> suf(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + C * a[i];
  }
  vector<set<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (adj[i].find(j) == adj[i].end()) {
        ans += A * a[i] + B * a[j] + suf[n - j - 1];
      }
      // for (int k = j + 1; k < n; k++) {
      //   if (adj[i].find(k) == adj[i].end() && adj[i].find(j) == adj[i].end() && adj[j].find(k) == adj[j].end()) {
      //     ans += A * a[i] + B * a[j] + C * a[k];
      //   }
      // } 
    }
    for (int k = i + 1; k < n; k++) {
      if (adj[i].find(k))
    }
    // for (int j : adj[i]) {
    //   for (int k : adj[j]) {
    //     // dbg(i, j, k);
    //     if (i < j && j < k) {
    //       dbg(i, j, k);
    //       ans -= A * a[i] + B * a[j] + C * a[k];        
    //     }
    //   }
    // }
  }
  cout << ans << '\n';
}


