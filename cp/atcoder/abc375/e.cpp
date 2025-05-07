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
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  int sum = accumulate(b.begin() + 1, b.end(), int(0));
  if (sum % 3 != 0) {
    cout << "-1\n";
    return 0;
  }
  const int INF = 1e9, partial = sum / 3;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(partial + 1, vector<int>(partial + 1, INF)));
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int w_1 = 0; w_1 <= partial; w_1++) {
      for (int w_2 = 0; w_2 <= partial; w_2++) {
        // i to team 1
        if (w_1 >= b[i])
          dp[i][w_1][w_2] = min(dp[i][w_1][w_2], dp[i - 1][w_1 - b[i]][w_2] + (a[i] != 1));
        // i to team 2
        if (w_2 >= b[i])
          dp[i][w_1][w_2] = min(dp[i][w_1][w_2], dp[i - 1][w_1][w_2 - b[i]] + (a[i] != 2));
        // i to team 3
        dp[i][w_1][w_2] = min(dp[i][w_1][w_2], dp[i - 1][w_1][w_2] + (a[i] != 3));
      }
    }
  }
  cout << (dp[n][partial][partial] == INF ? -1 : dp[n][partial][partial]);
}