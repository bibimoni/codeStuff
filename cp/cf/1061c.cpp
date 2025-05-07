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
#define int long long

const int N = 1e6 + 5, MOD = (int) 1e9 + 7;

int dp[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    vector<int> divs;
    for(int j = 1; j * j <= a[i]; j++) {
      if(a[i] % j == 0) {
        divs.push_back(j);
        if(a[i] != j * j) {
          divs.push_back(a[i] / j);
        }
      }
    }
    sort(divs.begin(), divs.end(), greater<int>());
    for(int j : divs) {
      // dp[j] = dp[j] + dp[j - 1] 
      // actual form dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] // j is divisor of a[i]
      //    (ans at i size j) = (ans at i - 1 size j) + (ans at i - 1 size j - 1)
      //     can be reduced to dp[j] = dp[j] + dp[j - 1]
      //        (curr ans size j) = (ans before size j) + (ans before size j - 1)
      // these 2 are basically the same
      // dp[i][j] = dp[i - 1][j] // j is not divisor of a[i]
      //     can be reduced to dp[j] = dp[j] // do nothing
      (dp[j] += dp[j - 1]) %= MOD; 
    }
  }
  cout << accumulate(dp + 1, dp + n + 1, 0ll, [&] (int i, int j) {
    return (i + j) % MOD;
  });
}

