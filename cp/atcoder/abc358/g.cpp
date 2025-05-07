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
  int h, w, k;
  cin >> h >> w >> k;
  int xs, ys;
  cin >> xs >> ys;
  xs -= 1;
  ys -= 1;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  const int INF = int(1e18);
  vector<vector<vector<int>>> dp(min(h * w, k) + 1, vector<vector<int>>(h, vector<int>(w, -INF)));
  dp[0][xs][ys] = 0;
  const vector<int> d = {-1, 0, 1, 0, -1};
  for (int step = 1; step <= min(h * w, k); step++) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        dp[step][i][j] = dp[step - 1][i][j] + a[i][j];
        for (int k = 0; k < 4; k++) {
          int px = i + d[k];
          int py = j + d[k + 1];
          if (px < 0 || py < 0 || px >= h || py >= w) {
            continue;
          }
          dp[step][i][j] = max(dp[step - 1][px][py] + a[i][j], dp[step][i][j]);
        }
      }
    }
  }
  int ans = 0;
  for (int step = 1; step <= min(h * w, k); step++) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        ans = max(ans, (k - step) * a[i][j] + dp[step][i][j]);
      }
    }
  }   
  cout << ans << '\n';
}

