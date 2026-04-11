#include <bits/stdc++.h>
using namespace std;
#define CLOVE2004 signed main()
// #define ll long long
#define int long long
// const int maxn = 2e5 + 7e4;
CLOVE2004 {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  // vector<int> maxpos(26, 0);
  // vector<int> minpos(26, 1e9);
  // vector<string> a(n + 1);
  // vector<vector<bool>> check(k + 1, vector<bool>(k + 1, true));
  // for (int i = 1; i <= n; ++i) {
  //   cin >> a[i];
  //   for (int j1 = 0; j1 < k; ++j1) {
  //     for (int j2 = j1 + 1; j2 < k; ++j2) {
  //       int k1 = a[i][j1] - 'A';
  //       int k2 = a[i][j2] - 'A';
  //       check[k1][k2] = false; // k1 đứng sau k2 -> false;
  //     }
  //   }
  // }
  int maxn = (1LL << k);
  vector<int> dp(maxn + 5, 0);
  vector<int> tmp(26, 0);
  // for (int i = 0; i < k; ++i) {
  //   for (int j = 0; j < k; ++j) {
  //     if (i != j) {
  //       if (check[i][j] == true)
  //         tmp[i] ^= (1LL << j);
  //     }
  //   }
  // }
  // // cout << tmp[2] << "\n";
  // for (int i = 0; i < k; ++i)
  //   dp[(1LL << i)] = 1;
  // int cur;
  // for (int i = 1; i < maxn; ++i) {
  //   if (dp[i] == 0)
  //     continue;
  //   for (int j = 0; j < k; ++j) {
  //     if ((i & (1LL << j)) == 0) {
  //       cur = i ^ (1LL << j);
  //       if ((tmp[j] & i) == i) {
  //         dp[cur] = max(dp[cur], dp[i] + 1);
  //       }
  //     }
  //   }
  // }
  // int ans = 0;
  // for (int i = 0; i < maxn; ++i)
  //   ans = max(ans, dp[i]);
  // cout << ans;
  return 0;
}
