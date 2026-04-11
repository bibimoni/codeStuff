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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> w(n + 1), h(n + 1), b(n + 1);
  int sum_w = 0;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> h[i] >> b[i];
    sum_w += w[i];
  }
  // dp[i][j]: max happiness when for the first i part, with the head
  // has weight j

  vector<int> dp(sum_w + 1);
  for (int i = 1; i <= n; i++) {
    vector<int> ndp(sum_w + 1);
    for (int j = 0; j <= sum_w; j++) {
      // attach to body
      ndp[j] = max(ndp[j], dp[j] + b[i]);
      // attach to head
      if (j >= w[i]) {
        ndp[j] = max(ndp[j], dp[j - w[i]] + h[i]);
      }
    }
    swap(ndp, dp);
  }

  int ans = 0;
  for (int j = 0; j <= sum_w; j++) {
    if (j <= sum_w - j) {
      ans = max(ans, dp[j]);
    }
  }

  cout << ans << '\n';
}
