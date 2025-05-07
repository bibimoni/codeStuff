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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    vector<int> suf(n + 2, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    reverse(a.begin() + 1, a.end());
    for (int i = n; i >= 1; i--) {
      suf[i] = suf[i + 1] + a[i];
    }
    vector<int> dp(n + 2, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int l = 1, r = i, ret = -1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (suf[m] - suf[i + 1] > x) {
          l = m + 1;
          ret = m;
        } else {
          r = m - 1;
        }
      }
      dbg(ret, i);
      if (ret != -1) {
        dp[i] = dp[ret - 1] + (i - ret);
      } else {
        dp[i] = i;
      }
    }
    cout << accumulate(dp.begin() + 1, dp.end(), 0ll) << '\n';
  }
}


