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
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    const int INF = n;
    vector<array<int, 3>> dp(n + 1, array<int, 3>{INF, INF, INF});    
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
      if (!a[i + 1]) {
        dp[i + 1][0] = min({dp[i][0] + 1, dp[i][1] + 1, dp[i][2] + 1, dp[i + 1][0]});
      }
      if (a[i + 1] > 4) {
        dp[i + 1][]
      }
    }
  }
}

