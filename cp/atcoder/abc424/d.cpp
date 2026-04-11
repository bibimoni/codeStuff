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
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
      cin >> a[i];
    }

    auto get = [&](int x, int y) -> vector<pair<int, int>> {
      vector<pair<int, int>> res;
      for (int i = x; i < h; i += 2) {
        for (int j = y; j < w; j += 2) {
          res.emplace_back(i, j);
        }
      }
      return res;
    };

    auto check = [&](vector<string> &b) -> bool {
      dbg(b);
      for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
          if (b[i][j] == '.' || b[i + 1][j] == '.' || b[i][j + 1] == '.' ||
              b[i + 1][j + 1] == '.') {
            continue;
          }
          dbg(i, j);
          return false;
        }
      }
      return true;
    };

    int ans = 1e9;
    vector<pair<int, int>> ll;
    ll.push_back({1, 1});
    if (h % 2 == 0) {
      ll.push_back({0, 1});
    }
    if (w % 2 == 0) {
      ll.push_back({1, 0});
    }

    for (auto [sx, sy] : ll) {
      auto pos = get(sx, sy);
      dbg(pos);
      int cnt = pos.size();
      for (int mask = 0; mask < (1 << cnt); mask++) {
        auto b = a;
        dbg(cnt, pos);
        int cur = 0;
        for (int i = 0; i < cnt; i++) {
          if ((mask >> i) & 1) {
            auto [x, y] = pos[i];
            if (b[x][y] == '#') {
              b[x][y] = '.';
              cur += 1;
            }
          }
        }

        dbg(b);
        if (check(b)) {
          ans = min(ans, cur);
        }
      }
    }

    cout << ans << '\n';
  }
}
