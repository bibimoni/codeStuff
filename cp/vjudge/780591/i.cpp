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

int dp1[41][2501][2501];
int dp2[41][2501][2501];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  s = "#" + s;

  memset(dp1, 0, sizeof dp1);
  memset(dp2, 0, sizeof dp2);

  dp1[0][0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int n_num = 0; n_num <= k; n_num++) {
      for (int na_num = 0; na_num <= k; na_num++) {
        if (!dp1[i][n_num][na_num])
          continue;

        if (s[i] != '?') {
          if (s[i] == 'N' && n_num + 1 <= k)
            dp1[i][n_num + 1][na_num] = 1;
          else if (s[i] == 'A' && na_num + n_num <= k)
            dp1[i][n_num][na_num + n_num] = 1;
          else {
          }
        } else {
        }
      }
    }
  }
}
