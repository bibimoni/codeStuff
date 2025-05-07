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
  freopen("talent.in", "r", stdin);
  freopen("talent.out", "w", stdout);
  int n, w;
  cin >> n >> w;
  vector<int> cow_w(n + 1), cow_t(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> cow_w[i] >> cow_t[i];
  }

  const int INF = 1e9;
  auto is_ratio_good = [&] (int ratio) -> int {
    vector<int> dp(w + 1, -INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      int v = 1000 * cow_t[i] - ratio * cow_w[i];
      for (int j = w; j >= 0; j--) {
        int f = min(j + cow_w[i], w);
        if (dp[j] == -INF) {
          continue;
        }
        dp[f] = max(dp[f], dp[j] + v);
      }
    }
    return dp[w] >= 0;
  };

  int lo = 0, hi = 1000 * 250 * 1000, ret = 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (is_ratio_good(mid)) {
      lo = mid + 1;
      ret = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << ret;
}