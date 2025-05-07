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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, h;
    cin >> n >> h;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    // vector<vector<vector<vector<pair<int, int>>>>> dp
    //   (n + 1, vector<vector<vector<pair<int, int>>>>(3, vector<vector<pair<int, int>>>(2, vector<pair<int, int>>(2, {0, 0}))));
    // dp[0][0][0][0] = {0, h}; dp[0][0][0][1] = {0, h};
    // for(int i = 1; i <= n; i++) {
    //   int power = a[i] / 2;
    //   //not take
    //   for(int b : {0, 1}) {
    //     for(int g : {0, 1, 2}) {
    //       dp[i][g][b][0] = max({dp[i][g][b][0], dp[i - 1][g][b][1], dp[i - 1][g][b][0]});
    //     }
    //   }
    //   //take and use blue
    //   for(int b : {0}) {
    //     for(int g : {0, 1, 2}) {
    //       auto [cnt1, p1] = dp[i - 1][g][b][1];
    //       if(p1 * 3 > a[i]) {
    //         dp[i][g][b + 1][1] = max(dp[i][g][b + 1][1], {cnt1 + 1, p1 * 3 + power});  
    //       }
    //       auto [cnt0, p0] = dp[i - 1][g][b][0];
    //       if(p0 * 3 > a[i]) {
    //         dp[i][g][b + 1][1] = max(dp[i][g][b + 1][1], {cnt0 + 1, p0 * 3 + power});
    //       }
    //     }
    //   }
    //   //take and use green
    //   for(int g : {0, 1}) {
    //     for(int b : {0, 1}) {
    //       auto [cnt1, p1] = dp[i - 1][g][b][1];
    //       if(p1 * 2 > a[i]) {
    //         dp[i][g + 1][b][1] = max(dp[i][g + 1][b][1], {cnt1 + 1, p1 * 2 + power});  
    //       }
    //       auto [cnt0, p0] = dp[i - 1][g][b][0];
    //       if(p0 * 2 > a[i]) {
    //         dp[i][g + 1][b][1] = max(dp[i][g + 1][b][1], {cnt0 + 1, p0 * 2 + power});
    //       }
    //     }
    //   }
    //   //take and not use
    //   for(int b : {0, 1}) {
    //     for(int g : {0, 1, 2}) {
    //       auto [cnt1, p1] = dp[i - 1][g][b][1];
    //       if(p1 > a[i]) {
    //         dp[i][g][b][1] = max(dp[i][g][b][1], {cnt1 + 1, p1 + power});  
    //       }
    //       auto [cnt0, p0] = dp[i - 1][g][b][0];
    //       if(p0 > a[i]) {
    //         dp[i][g][b][1] = max(dp[i][g][b][1], {cnt0 + 1, p0 + power});
    //       }
    //     }
    //   }
    // }
    // int ans = 0;
    // for(int b : {0, 1}) {
    //   for(int g : {0, 1, 2}) {
    //     for(int j : {0, 1}) {
    //       ans = max(ans, dp[n][g][b][j].first);
    //     }
    //   }
    // }
    int ans = 0;
    for(int se = 2; se >= 0; se--) {
      vector<int> t = {2, 2, 2};
      t[se] = 3;
      // dbg(t);
      int curr = h, blue = 1, green = 2, cnt = 0, j = 0;
      for(int i = 1; i <= n; i++) {
        if(curr > a[i]) {
          curr += a[i] / 2;
          cnt++;
        }
        else {
          for(; j < 3; j++) {
            curr *= t[j];
            if(curr > a[i]) {
              curr += a[i] / 2;
              cnt++;
              j++;
              break;
            }
          }
        }
        // dbg(curr, j);
      }
      ans = max(ans, cnt);
    }
    cout << ans << '\n';
  }
}


