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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  const int ALP = 26;
  vector<vector<pair<int, int>>> warp(ALP);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if ('a' <= s[i][j] && s[i][j] <= 'z') {
        warp[s[i][j] - 'a'].push_back({i, j});
      }
    }
  }

  queue<pair<int, int>> que;
  const int inf = 1e9;
  vector dist(n, vector<int>(m, inf));
  que.push({0, 0});
  dist[0][0] = 0;
  vector<int> mark(ALP);
  const vector<int> dir{-1, 0, 1, 0, -1};
  while (que.size()) {
    auto [x, y] = que.front();
    dbg(x, y);
    que.pop();
    auto go = [&](int vx, int vy) -> void {
      if (vx < 0 || vy < 0 || vx >= n || vy >= m) {
        return;
      }

      if (dist[vx][vy] < inf || s[vx][vy] == '#') {
        return;
      }
      dist[vx][vy] = dist[x][y] + 1;
      que.push({vx, vy});
      return;
    };

    for (int k = 0; k < (int)dir.size() - 1; k++) {
      int vx = x + dir[k];
      int vy = y + dir[k + 1];
      go(vx, vy);
    }

    if ('a' <= s[x][y] && s[x][y] <= 'z') {
      int c = s[x][y] - 'a';
      if (mark[c]) {
        continue;
      }
      mark[c] = 1;
      for (auto p : warp[s[x][y] - 'a']) {
        go(p.first, p.second);
      }
    }
  }

  int ans = dist[n - 1][m - 1];
  if (dist[n - 1][m - 1] >= inf) {
    ans = -1;
  }
  cout << ans << '\n';
}
