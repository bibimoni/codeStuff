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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  auto ok = [&](int x, int y) -> int {
    return int(x >= 0 && y >= 0 && x < h && y < w);
  };
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      const vector<int> d{-1, 0, 1, 0, -1};
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int nx = i + d[k];
        int ny = j + d[k + 1];
        cnt += ok(nx, ny);
      }
      cout << cnt << " \n"[i == h - 1];
    }
  }
}
