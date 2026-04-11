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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> p(h + w - 1);
  for (int i = 0; i < h + w - 1; i++) {
    cin >> p[i];
  }

  auto check = [&](int coins) -> bool {
    vector<vector<int>> dp(h, vector<int>(w, -1));
    dp[0][0] = coins + a[0][0] >= p[0] ? coins + a[0][0] - p[0] : -1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (i == 0 && j == 0) {
          continue;
        }

        int best = -1;
        for (auto [nx, ny] : vector<pair<int, int>>{{i - 1, j}, {i, j - 1}}) {
          if (nx < 0 || ny < 0) {
            continue;
          }
          if (dp[nx][ny] == -1) {
            continue;
          }
          best = max(best, dp[nx][ny]);
        }

        if (best == -1) {
          continue;
        }
        if (best + a[i][j] >= p[i + j]) {
          dp[i][j] = best + a[i][j] - p[i + j];
        }
      }
    }
    return dp[h - 1][w - 1] != -1;
  };

  int lo = 0, hi = 1e18, ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      hi = mid - 1;
      ans = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans << '\n';
}
