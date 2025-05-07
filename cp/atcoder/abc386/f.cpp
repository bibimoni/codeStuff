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

const int INF = numeric_limits<int>::max(); 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int k;
  string s, t;
  cin >> k >> s >> t;
  int n = s.size(), m = t.size();
  if (abs(n - m) > k) {
    cout << "No\n";
    return 0;
  }
  s = " " + s;
  t = " " + t;
  // dp[i][j] = min(dp[i - 1][j - 1] + s[i] == t[j], dp[i - 1][j] + 1, dp[i][j - 1] + 1)
  vector dp (n + 1, vector (2 * k + 1, INF));
  dp[0][k] = 0;
  for (int i = 1; i <= n; i++) {
    vector ndp(2 * k + 1, INF);
    for (int j = i - k; j <= i + k; j++) {
      if (j < 0 || j > m) {
        continue;
      }
      if (i > 0 && j + k <= 2 * k) {
        dp[i][j + k] = min(dp[i][j + k], dp[i - 1][j + k] + 1);
      }
      if (i >= 0) {
        dp[i][j + k] = min(dp[i][j + k], dp[i][j + k - 1] + 1);
      }
    }
  }

}


