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
  int n, m;
  cin >> n >> m;
  vector<string> a(n + 1, string(m + 1, '.'));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = "." + a[i];
  }
  const int INF = int(1e9);
  vector<int> dp(int(1) << m, INF);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      vector<int> ndp(int(1) << m);
      for (int mask = 0; mask < (int(1) << m); mask++) {
        int to = j - 1;
        if((mask >> to) & 1) {
          if (a[i][j] == '.') {
            ndp[mask] = INF;
          } else {
            ndp[mask] = min(dp[mask], dp[mask ^ (int(1) << to)] + 1);
          }
        } else {
          ndp[mask] = min(dp[mask], dp[mask ^ (int(1) << to)]);
          if (a[i][j] == '#' && (j == 1 || (mask & (int(1) << (to - 1))) || a[i][j - 1] == '.')) {
            ndp[mask] += 1;
          }
        }
      }
      swap(ndp, dp);
    }
  }
  cout << *min_element(dp.begin(), dp.end());
}

