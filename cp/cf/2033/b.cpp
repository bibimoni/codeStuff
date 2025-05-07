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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int y = 0, x = i;
      int mx = 0;
      while (x < n && y < n) {
        mx = min(mx, a[x][y]);
        x += 1;
        y += 1;
      }
      ans += abs(mx);
    }
    for (int j = 1; j < n; j++) {
      int y = j, x = 0;
      int mx = 0;
      while (x < n && y < n) {
        mx = min(mx, a[x][y]);
        x += 1;
        y += 1;
      }
      ans += abs(mx);
    }
    cout << ans << '\n';
  }
}


