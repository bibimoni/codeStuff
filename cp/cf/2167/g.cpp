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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }

    const int inf = 1e18;
    vector<array<int, 2>> dp(n + 1, array<int, 2>{inf, inf});
    dp[1][0] = 0;
    dp[1][1] = c[1];
  }
}
