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
  int n, x;
  cin >> n >> x;
  vector<int> s(n), p(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> c[i] >> p[i];
  }
  vector<vector<long double>> dp((1 << n), vector<long double>(x + 1));  
  for (int j = 0; j <= x; j++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1 ^ 1) {
          if(j >= c[i]) {
            long double prb = (long double) p[i] / 100;
            dp[mask | (1 << i)][j] = max(prb * (dp[mask][j - c[i]] + s[i]) + (1 - prb) * dp[mask | (1 << i)][j - c[i]], dp[mask | (1 << i)][j]);
          }
        }
      }  
    }
  }
  long double ans = 0;
  for (int j = 0; j <= x; j++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      ans = max(ans, dp[mask][j]);
    }
  }
  cout << fixed << setprecision(9) << ans;
}


