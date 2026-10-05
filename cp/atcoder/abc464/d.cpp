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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<int> y(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> y[i];
    }
    const int64_t inf = 1e18;
    vector<array<int64_t, 2>> dp(n, {{-inf, -inf}});
    dp[0][0] = s[0] == 'R' ? 0 : -x[0];
    dp[0][1] = s[0] == 'S' ? 0 : -x[0];
    for (int i = 1; i < n; i++) {
      for (int prv = 0; prv < 2; prv++) {
        for (int cur = 0; cur < 2; cur++) {
          int v = s[i] == 'S';
          int g = v == cur ? 0 : -x[i];
          if (prv == 0 && cur == 1) {
            g += y[i - 1];
          }
          dp[i][cur] = max(dp[i][cur], dp[i - 1][prv] + g);
        }
      }
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
  }
}
