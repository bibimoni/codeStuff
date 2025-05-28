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
    int x, y, k;
    cin >> x >> y >> k;

    const int INF = 100;
    auto getAns = [&](int val) -> int {
      vector<int> divs;
      for (int i = 1; i * i <= val; i++) {
        if (val % i == 0) {
          divs.push_back(i);
          if (i * i != val) {
            divs.push_back(val / i);
          }
        }
      }
      sort(divs.begin(), divs.end());
      int n = divs.size();
      vector dp(n, INF);
      dp[0] = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
          if (divs[i] / divs[j] > k) {
            break;
          }
          if (divs[i] % divs[j] == 0) {
            dp[i] = min(dp[i], dp[j] + 1);
          }
        }
      }

      return dp[n - 1];
    };

    int ans = getAns(x / __gcd(x, y)) + getAns(y / __gcd(x, y));
    cout << (ans >= INF ? -1 : ans) << '\n';
  }
}
