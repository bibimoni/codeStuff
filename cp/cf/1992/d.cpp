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
    int n, m, k;
    cin >> n >> m >> k;
    string a;
    cin >> a;
    a = "L" + a + "L";
    const int INF = int(1e9);
    vector<int> dp(n + 2, INF);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
      if (a[i] == 'C') {
        continue;
      }
      for (int j = max(0ll, i - m); j <= i - 1; j++) {
        if (a[j] == 'L') {
          dp[i] = min(dp[i], dp[j]);
        }
      }
      if (a[i - 1] == 'W') {
        dp[i] = min(dp[i - 1] + 1ll, dp[i]);
      }
    }
    cout << (dp[n + 1] <= k ? "YES\n" : "NO\n");
  }
}


