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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<int> cnt(n + 1);
    for (int j = 1, i = 1; i <= n; i++) {
      cnt[j] += 1;
      if (i + 1 <= n && a[i] != a[i + 1]) {
        j += 1;
      }
    }
    const int INF = int(1e18);
    vector<int> dp(n + 1, INF);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      vector<int> ndp(n + 1, INF);
      for (int j = n; j >= 1; j--) {
        ndp[j] = min(ndp[j], dp[j - 1] + 1);
      }
      for (int j = n - cnt[i]; j >= 0; j--) {
        ndp[j] = min(ndp[j], dp[j + cnt[i]]);
      }
      swap(ndp, dp);
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
  }
}


