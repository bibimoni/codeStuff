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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<string> ans(n, string(m, 'x'));

    x -= 1;
    y -= 1;
    ans[x][y] = '.';

    int cx = x, cy = y;
    if (!(cx == 0 || cx == n - 1 || cy == 0 || cy == m - 1)) {
      while (cx > 0) {
        cx -= 1;
        ans[cx][cy] = 'v';
      }
    }
    dbg(ans);
    for (int i = 0; i < n; i++) {
      int tx = i, ty = 0;
      if (ans[tx][ty] == 'x') {
        ans[tx][ty] = '^';
      }
      ty = m - 1;
      if (ans[tx][ty] == 'x') {
        ans[tx][ty] = 'v';
      }
    }

    for (int i = 0; i < m; i++) {
      int tx = 0, ty = i;
      if (ans[tx][ty] == 'x') {
        ans[tx][ty] = '>';
      }
      tx = n - 1;
      if (ans[tx][ty] == 'x') {
        ans[tx][ty] = '<';
      }
    }

    if (ans[0][0] != '.') {
      ans[0][0] = '>';
    }
    if (ans[n - 1][m - 1] != '.') {
      ans[n - 1][m - 1] = '<';
    }

    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (ans[i][j] == 'x') {
          ans[i][j] = '<';
        }
      }
    }

    for (int i = 0; i < n; i++) {
      cout << ans[i] << "\n";
    }
  }
}
