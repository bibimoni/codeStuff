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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<array<int, 2>>> pre(31, vector<array<int, 2>>(n + 1, {{0, 0}}));
    for(int i = 1; i <= n; i++) {
      for(int j = 30; j >= 0; j--) {
        int u = (a[i] >> j) & 1;
        if(u == 1) {
          pre[j][i][u] = pre[j][i - 1][u ^ 1] + u;
          pre[j][i][u ^ 1] = pre[j][i - 1][u];
        }
        else {
          pre[j][i][1 - u] = pre[j][i - 1][1 - u];
          pre[j][i][u] = pre[j][i - 1][u] + (u ^ 1);
        }
      }
    }
    vector<vector<array<int, 2>>> suf(31, vector<array<int, 2>>(n + 1, {{0, 0}}));
    for(int i = n; i >= 1; i--) {
      for(int j = 30; j >= 0; j--) {
        int u = (a[i] >> j) & 1;
        if(u == 1) {
          suf[j][i][u] = suf[j][i + 1][u ^ 1] + u;
          suf[j][i][u ^ 1] = suf[j][i + 1][u];
        }
        else {
          suf[j][i][1 - u] = suf[j][i + 1][1 - u];
          suf[j][i][u] = suf[j][i + 1][u] + (u ^ 1);
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 30; j >= 0; j--) {
        if((a[i] >> j) & 1) {
          ans += (pre[j][i][0] * suf[j][i][1]) + (pre[i][j][1] * suf[i][j][0]);
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}


