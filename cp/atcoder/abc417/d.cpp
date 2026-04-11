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
  vector<int> p(n), a(n), b(n), pre(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> a[i] >> b[i];
    pre[i + 1] = pre[i] + b[i];
  }

  const int mxn = 1000;
  vector<vector<int>> dp(n + 1, vector<int>(mxn + 1));
  iota(dp[n].begin(), dp[n].end(), 0);

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= mxn; j++) {
      if (j <= p[i]) {
        dp[i][j] = dp[i + 1][j + a[i]];
      } else {
        dp[i][j] = dp[i + 1][max(int(0), j - b[i])];
      }
    }
  }

  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    int lo = -1, hi = n - 1, ret = -2;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (x - pre[mid + 1] <= mxn) {
        hi = mid - 1;
        ret = mid;
      } else {
        lo = mid + 1;
      }
    }

    if (ret == -2) {
      cout << x - pre[n] << '\n';
    } else {
      cout << dp[ret + 1][x - pre[ret + 1]] << '\n';
    }
  }
}
