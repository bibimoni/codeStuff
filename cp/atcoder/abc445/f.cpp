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
  int n, k;
  cin >> n >> k;
  vector c(n, vector(n, 0));
  const int64_t INF = int(1e18 + 7);
  vector<vector<int64_t>> dp(n, vector<int64_t>(n, INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
      dp[i][j] = c[i][j];
    }
  }

  // for (int v = 0; v < n; v++) {
  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < n; j++) {
  //       if (dp[i][j] > dp[i][v] + dp[v][j]) {
  //         dp[i][j] = dp[i][v] + dp[v][j];
  //       }
  //     }
  //   }
  // }

  const int L = 32;
  vector up(L, vector(n, 0));
  vector sum(L, vector(n, int64_t(0)));
  for (int i = 0; i < n; i++) {
    sum[0][i] = c[i][i];
    for (int j = 0; j < n; j++) {
      if (sum[0][i] > c[i][j]) {
        sum[0][i] = c[i][j];
        up[0][i] = j;
      }
    }
  }
  for (int v = 1; v < L; v++) {
  }
}
