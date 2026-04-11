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
    int n, k;
    cin >> n >> k;

    vector<int> b;
    int x = n;
    while (x) {
      b.push_back(x % 2);
      x >>= 1;
    }

    int l = b.size();
    vector<vector<array<int, 2>>> dp(
        l + 1, vector<array<int, 2>>(k + 1, array<int, 2>{-1, -1}));
    dp[0][0][1] = 0;
    for (int i = 0; i < l; i++) {
      for (int bb = 0; bb <= k; bb++) {
        for (int cur : {0, 1}) {
        }
      }
    }
  }
}
