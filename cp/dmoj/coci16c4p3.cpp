/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(n + 1);
  int sum_c = 0;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    sum_c += c[i];
  }

  const int INF = 1e9;
  vector dp(sum_c + 1, -INF);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> ndp(sum_c + 1, 0);
    for (int j = 0; j <= sum_c; j++) {
      ndp[j] = dp[j];
      ndp[j] = max(ndp[j], dp[abs(j - c[i])] + c[i]);
      if (j + c[i] <= sum_c) {
        ndp[j] = max(ndp[j], dp[j + c[i]] + c[i]);
      }
    }
    swap(ndp, dp);
  }
  dbg(dp[0]);

  cout << sum_c - dp[0] / 2;
}
