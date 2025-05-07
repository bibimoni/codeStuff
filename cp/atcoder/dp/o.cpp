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
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  const int MOD = int(1e9) + 7;
  vector<int> dp(int(1) << n, 0);
  dp[0] = 1;
  for (int mask = 0; mask < (int(1) << n); mask++) {
    for (int j = 0; j < n; j++) {
      int i = __builtin_popcountll(mask ^ (int(1) << j));
      // the next women will me the (n0 of bit 1) + 1
      if (((mask >> j) & 1) && a[i][j]) {
        (dp[mask] += dp[mask ^ (int(1) << j)]) %= MOD;
      }
    }
  }
  // dbg(dp);
  cout << dp[(int(1) << n) - 1];
}

