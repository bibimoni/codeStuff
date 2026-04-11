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

    const int inf = 1e9;
    vector d(vector(h, vector(w + 1, array<int, 4>{inf, inf, inf, inf})));
    vector was(vector(h, vector(w + 1, array<int, 4>{0, 0, 0, 0})));
    vector cost{2, 3, 1};
    vector dy{0, 1, 0, -1};
    vector dx{1, 0, -1, 0};
    vector op{2, 3, 0, 1};

    // 0 down 1 right 2 up 3 left
    // A 0 xor 2 == 2 and 1 xor 3 == 2 cost 0 else cost 1
    // B 3 xor 0 == 3 and 1 xor 2 == 3 cost 0 else cost 1
    // C 3 xor 2 == 1 and 0 xor 1 == 1 cost 0 else cost 1

    deque<array<int, 3>> dq;
    dq.push_back({0, 0, 3});
    d[0][0][3] = 0;
    while (dq.size()) {
      auto f = dq.front();
      dq.pop_front();
      int x = f[0], y = f[1], dir = f[2];
      // dbg(f, d[x][y][dir]);
      if (was[x][y][dir]) {
        continue;
      }
      was[x][y][dir] = 1;
      for (int ndir = 0; ndir < 4; ndir++) {
        int vx = x + dx[ndir];
        int vy = y + dy[ndir];
        int c = (dir ^ ndir) == cost[a[x][y] - 'A'] ? 0 : 1;
        if ((vx >= 0 && vy >= 0 && vx < h && vy < w) ||
            (vx == h - 1 && vy == w)) {
          if (vx >= 0 && vy >= 0 && vx < h && vy < w) {
            d[vx][vy][op[ndir]] = min(d[x][y][dir] + c, d[vx][vy][op[ndir]]);
            if (c == 0) {
              dq.push_front({vx, vy, op[ndir]});
            } else {
              dq.push_back({vx, vy, op[ndir]});
            }
          } else {
            d[vx][vy][op[ndir]] = min(d[x][y][dir] + c, d[vx][vy][op[ndir]]);
          }
        }
      }
    }

    int ans = d[h - 1][w][3];

    cout << ans << '\n';
  }
}
