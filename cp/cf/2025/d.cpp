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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] + (a[i] == 0);
  }
  const int INF = int(1e9);
  vector<int> sum(m + 2, 0), dp(m + 1, -INF);
  dp[0] = 0;
  // I >= a[i]
  // p[i] = 5, I = 3
  // S = p[i] - I = 2 >= 2 = a[i]
  // I <= -a[i] + p[i] = 2 + 5 = 7
  // p[i] - I >= -a[i]
  // I - p[i] <= a[i]
  // I <= a[i] + p[i]
  // I = 0, p[i]
  // dp[i][I] = max(dp[i - 1][I], dp[i - 1][I - 1])
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      vector<int> ndp(m + 1);
      for (int j = 1; j <= m; j++) {
        sum[j] += sum[j - 1];
      }
      ndp[0] = dp[0] + sum[0];
      for (int j = 1; j <= m; j++) {
        ndp[j] = max(dp[j - 1] + sum[j - 1], dp[j] + sum[j]);
      }
      sum = vector<int>(m + 2, 0);
      swap(dp, ndp);
    } else if (a[i] > 0) {
      sum[a[i]] += 1;
    } else {
      if (a[i] + p[i] < 0) {
        continue;
      }
      sum[0] += 1;
      sum[min(m, a[i] + p[i]) + 1] -= 1;
    }
  }
  for (int j = 1; j <= m; j++) {
    sum[j] += sum[j - 1];
  }
  for (int i = 0; i <= m; i++) {
    dp[i] += sum[i];
  }
  cout << *max_element(dp.begin(), dp.end());
}


