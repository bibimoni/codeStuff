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
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  vector<vector<int>> pr(26, vector<int>(n + 1, -1));
  for (int c = 0; c < 26; c++) {
    int x = -1;
    for (int i = 1; i <= n; i++) {
      if (s[i] == char(c + 'a')) {
        pr[c][i] = x;
        x = i;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (s[i] == char(c + 'a')) {
        int t = c;
        x = i;
        while (t-- && x != -1) {
          x = pr[c][x];
        }
        pr[c][i] = x;
      }
    }
  }
  vector<vector<int>> dp(26, vector<int>(n + 1, 0));
  int ans = 0;
  for (int c = 0; c < 26; c++) {
    for (int i = 1; i <= n; i++) {
      dp[c][i] = dp[c][i - 1];
      if (pr[c][i] != -1) {
        dp[c][i] = max(dp[c][i], c + 1);
      }
      for (int k = 0; k < c; k++) {
        if (pr[c][i] > 0) {
          dp[c][i] = max({dp[c][i], dp[k][pr[c][i] - 1] + c + 1, c + 1});
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dp[c][i]);
    }
  }
  cout << ans << '\n';
}

