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
const int MOD = (int) 1e9 + 7;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n * m == 1) {
    cout << "0\n";
    return 0;
  }
  if (n * m == 2) {
    cout << "1\n";
    return 0;
  }
  vector<int> dp(int(1) << n, 0);
  // 011
  // 011
  dp[(int(1) << n) - 1] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      vector<int> ndp(int(1) << n, 0);
      for (int mask = 0; mask < (int(1) << n); mask++) {
        int to = j - 1;
        if ((mask >> to) & 1) {
          (ndp[mask] += dp[mask ^ (int(1) << to)]) %= MOD;
          if (j >= 2 && (mask & (1 << to)) && (mask & (1 << (to - 1)))) {
            (ndp[mask] += dp[mask ^ (int(1) << (to - 1))]) %= MOD;
          }
        } else {
          (ndp[mask] += dp[mask ^ (int(1) << to)]) %= MOD;
        }
      }
      swap(dp, ndp);
    }
  }
  cout << dp[(int(1) << n) - 1];
}

