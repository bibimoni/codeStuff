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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto check = [&] (int val) -> bool {
      vector<int> b(n);
      for (int i = 0; i < n; i++) {
        b[i] = (a[i] >= val ? 1 : -1);
      }
      vector<int> dp(n, 0);
      dp[0] = b[0];
      for (int i = 1; i < n; i++) {
        if (i % k == 0) {
          dp[i] = max(dp[i - k], b[i]);
        } else {
          dp[i] = dp[i - 1] + b[i];
          if (i > k) {
            dp[i] = max(dp[i], dp[i - k]);
          }
        }
      }
      return dp[n - 1] > 0;
    };
    int l = 0, r = *max_element(a.begin(), a.end()), ret = 0;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (check(m)) {
        l = m + 1;
        ret = m;
      } else {
        r = m - 1;
      }
    }
    cout << ret << '\n';
  }
}


