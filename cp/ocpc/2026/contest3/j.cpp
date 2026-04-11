/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  // bool ok = false;

  vector<vector<int>> ans(n, vector<int>(n));
  auto dfs = [&](auto &&self, int i, int j, vector<vector<int>> cur) -> void {
    if (j == n - 1) {
      for (int y = 0; y < j; y++) {
        cur[i][j] -= cur[i][y];
      }
      if (abs(cur[i][j]) > 1) {
        return;
      }
      i += 1;
      j = 0;
    }
    if (i == n - 1) {
      bool chk = true;
      for (int y = 0; chk && y < n; y++) {
        for (int x = 0; x < i; x++) {
          cur[i][y] -= cur[x][y];
          if (abs(cur[i][y]) > 1) {
            chk = false;
            break;
          }
        }
      }
      if (!chk) {
        return;
      }

      for (int y = 0; chk && y < n; y++) {
        for (int x = 0; x < n; x++) {
          if (x != y)
            chk &= cur[x][y] != cur[y][x];
        }
      }

      if (chk) {
        ans = cur;
        return;
      }
      return;
    }

    for (int val : {-1, 0, 1}) {
      cur[i][j] = val;
      self(self, i, j + 1, cur);
    }
  };
  dfs(dfs, 0, 0, ans);
  dbg(ans);
}
