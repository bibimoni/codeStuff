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
  int n, m;
  cin >> n >> m;
  int kv, x, y;
  cin >> kv >> x >> y;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const int INF = int(1e18);
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  for (int k = 0; k < m; k++) {
    vector<int> ndp(n + 1, INF);
    for (int i = 1; i <= n; i++) {
      int curr = a[i];
      for (int j = i; j >= 1; j--) {
        curr = gcd(curr, a[j]);
        int val = (curr == kv ? x : y);
        dbg(k, i, j, ndp[i], curr == kv , val);
        ndp[i] = min(ndp[i], dp[j - 1] + val);
      }
    }
    dbg(ndp);
    dp = ndp;
  }
  cout << dp[n];
}
