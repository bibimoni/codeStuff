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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    const int inf = 1e9;
    vector<int> dp(8, 1);
    dp[a[0]] = 0;
    for (int i = 1; i < n; i++) {
      int v = a[i];
      vector<int> ndp(8, inf);
      for (int x = 1; x <= 7; x++) {
        for (int y = 1; y <= 7; y++) {
          if (x + y == 7 || x == y) {
            continue;
          }

          ndp[x] = min(ndp[x], (x != v) + dp[y]);
        }
      }

      swap(ndp, dp);
    }

    int ans = inf;
    for (int i = 1; i <= 7; i++) {
      ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}
