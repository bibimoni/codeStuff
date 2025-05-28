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
  int curVal = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      curVal ^= a[i][j];
    }
  }

  auto toOne = [&](int x, int y) -> int { return x * w + y; };
  int ans = curVal;
  auto dfs = [&](auto &&self, int x, int y, int val, int mask) -> void {
    if (x == h - 1 && y == w) {
      ans = max(ans, val);
      return;
    }
    if (y == w) {
      y = 0;
      x += 1;
    }
    int id = toOne(x, y);
    if ((mask >> id) & 1) {
      self(self, x, y + 1, val, mask);
    } else {
      self(self, x, y + 1, val ^ a[x][y], mask);
      if (y + 1 < w && (((mask >> toOne(x, y + 1) & 1) ^ 1))) {
        self(self, x, y + 1, val, mask | (1 << id) | (1 << toOne(x, y + 1)));
      }
      if (x + 1 < h && (((mask >> toOne(x + 1, y) & 1) ^ 1))) {
        self(self, x, y + 1, val, mask | (1 << id) | (1 << toOne(x + 1, y)));
      }
    }
  };
  dfs(dfs, 0, 0, 0, 0);
  cout << ans << '\n';
}
