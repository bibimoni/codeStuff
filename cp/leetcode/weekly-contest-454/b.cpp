#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int specialTriplets(vector<int> &a) {
    int n = int(a.size());
    const int MOD = 1e9 + 7;
    int mx = *max_element(a.begin(), a.end());
    vector<int> cnt(mx + 1, 0);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      if (a[i] * 2 <= mx) {
        dp[i] = cnt[a[i] * 2];
      }
      cnt[a[i]] += 1;
    }
    long long ans = 0;
    cnt = vector<int>(mx + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] * 2 <= mx) {
        ans += (dp[i] * cnt[a[i] * 2]) % MOD;
        ans %= MOD;
      }
      cnt[a[i]] += 1;
    }
    return ans;
  }
};
