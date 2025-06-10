#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long maximumProfit(vector<int> &v, int k) {
    int n = (int)v.size();
    const int INF = 1e9;

    vector<int> dp(2 * k + 2, -INF);
    dp[k] = 0;

    for (int i = 0; i < n; i++) {
      vector<int> ndp(2 * k + 2, -INF);
      for (int j = 0; j <= 2 * k + 1; j++) {
        ndp[j] = dp[j];
        if (j > 0) {
          ndp[j] = max(ndp[j], dp[j - 1] + v[i]);
        }
        if (j <= 2 * k)
      }
    }
  }
};
