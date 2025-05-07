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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= n; i++) {
    if (i == n) {
      adj[i].push_back(1);
    } else {
      adj[i].push_back(i + 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }

}


