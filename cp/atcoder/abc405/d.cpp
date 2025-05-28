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
  vector<string> a(h);
  queue<array<int, 3>> que;
  vector<pair<int, int>> exit;
  vector<vector<int>> mark(h, vector<int>(w, 0));
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    for (int j = 0; j < w; j++) {
      if (a[i][j] == 'E') {
        cnt += 1;
        que.push({i, j, cnt});
        mark[i][j] = cnt;
        exit.push_back({i, j});
      }
    }
  }

  auto get = [&](int vx, int vy, int x, int y) -> char {
    if (vy == y - 1) {
      return '>';
    } else if (vy == y + 1) {
      return '<';
    } else if (vx == x + 1) {
      return '^';
    }
    return 'v';
  };
  vector<string> ans = a;

  const vector<int> dir{-1, 0, 1, 0, -1};
  while (que.size()) {
    auto p = que.front();
    int ux = p[0], uy = p[1], c = p[2];
    que.pop();
    for (int k = 0; k < 4; k++) {
      int vx = ux + dir[k];
      int vy = uy + dir[k + 1];
      if (vx < 0 || vy < 0 || vx >= h || vy >= w) {
        continue;
      }
      if (a[vx][vy] == '#' || a[vx][vy] == 'E') {
        continue;
      }
      if (mark[vx][vy]) {
        continue;
      }
      mark[vx][vy] = c;
      que.push({vx, vy, c});
      ans[vx][vy] = get(vx, vy, ux, uy);
    }
  }

  for (string s : ans) {
    cout << s << '\n';
  }
}
