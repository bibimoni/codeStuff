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

const vector<pair<int, int>> dir = {
  {-1, 0},
  {1, 0},
  {0, 1},
  {0, -1}
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;

  int sx, sy;
  cin >> sx >> sy;
  --sx, --sy;

  vector a(n, vector(m, 0ll));
  vector vis(n, vector(m, false));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  auto check = [&] (int x, int y) -> bool {
      return 0 <= x && x < n && 0 <= y && y < m;
  };

  int cur = a[sx][sy]; 
  vis[sx][sy] = true;
  priority_queue<pair<int, pair<int, int>>> pq;
  for (auto [dx, dy] : dir) {
    int nx = sx + dx;
    int ny = sy + dy;
    if (check(nx, ny)) {
      pq.push({-a[nx][ny], {nx, ny}});
      vis[nx][ny] = true;
    }
  }

  while (!pq.empty()) {
    auto [val, pos] = pq.top(); pq.pop();
    auto [px, py] = pos;
    if (-val < (cur + x - 1) / x) {
      cur += -val;
      for (auto [dx, dy] : dir) {
        int nx = px + dx;
        int ny = py + dy;
        if (check(nx, ny) and not vis[nx][ny]) {
          pq.push({-a[nx][ny], {nx, ny}});
          vis[nx][ny] = true;
        }
      }
    }
  }
  cout << cur;
}


