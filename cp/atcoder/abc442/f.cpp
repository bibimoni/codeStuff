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
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = "." + a[i] + "#";
  }

  vector<int> dp(n + 2);
  const int inf = 1e9;
  for (auto &v : a) {
    vector pre(n + 2, 0);
    for (int i = 1; i <= n + 1; i++) {
      pre[i] = pre[i - 1] + int(v[i] == '.');
    }
    vector ndp(n + 2, inf);
    for (int i = n + 1; i >= 1; i--) {
      if (i <= n) {
        ndp[i] = ndp[i + 1];
      }
      ndp[i] = min(ndp[i], dp[i] + (i - 1) - 2 * pre[i - 1] + pre[n + 1]);
    }
    swap(ndp, dp);
  }

  int ans = dp[1];
  cout << ans << '\n';
}
