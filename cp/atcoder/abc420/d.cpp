/**j
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
  vector<string> a(h);
  int xs = -1, ys = -1, xg = -1, yg = -1;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    for (int j = 0; j < w; j++) {
      if (a[i][j] == 'S') {
        xs = i;
        ys = j;
      } else if (a[i][j] == 'G') {
        xg = i;
        yg = j;
      }
    }
  }

  assert(xs != -1 && ys != -1 && xg != -1 && yg != -1);

  vector<int> dir{-1, 0, 1, 0, -1};

  // vector<vector<array<int, 2>>> was(h, vector<array<int, 2>>(w, {0, 0}));
  const int inf = 1e9;
  vector<vector<array<int, 2>>> d(h, vector<array<int, 2>>(w, {inf, inf}));
  d[xs][ys][0] = 0;

  set<array<int, 4>> st;
  st.insert({0, 0, xs, ys});

  while (st.size()) {
    auto p = *st.begin();
    st.erase(st.begin());
    int uw = p[0], opt = p[1], ux = p[2], uy = p[3];
    if (uw != d[ux][uy][opt]) {
      continue;
    }
    for (int k = 0; k < 4; k++) {
      int vx = ux + dir[k];
      int vy = uy + dir[k + 1];
      if (vx < 0 || vx >= h || vy < 0 || vy >= w) {
        continue;
      }
      if (a[vx][vy] == '#') {
        continue;
      }
      if ((opt == 0 && a[vx][vy] == 'x') || (opt == 1 && a[vx][vy] == 'o')) {
        continue;
      }
      int nopt = opt ^ int(a[vx][vy] == '?');
      if (d[ux][uy][opt] + 1 < d[vx][vy][nopt]) {
        d[vx][vy][nopt] = d[ux][uy][opt] + 1;
        st.insert({d[vx][vy][nopt], nopt, vx, vy});
      }
    }
  }

  int ans = min(d[xg][yg][0], d[xg][yg][1]);
  if (ans == inf) {
    ans = -1;
  }
  cout << ans << '\n';
}
