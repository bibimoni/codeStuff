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

const int INF = (int) 1e9;

 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  vector<int> dir = {-1, 0, 1, 0, -1};
  queue<pair<int, int>> que;
  vector<vector<int>> d(n, vector<int>(m, -1));
  que.push({0, 0});
  d[0][0] = 0;
  int ans = INF;
  while (que.size()) {
    auto [ux, uy] = que.front();
    que.pop();
    if (ans != INF) {
      break;
    }
    dbg("u", ux, uy);
    for (int i = 0; i < 4; i++) {
      int vx = ux + dir[i];
      int vy = uy + dir[i + 1];
      vy = (vy + m) % m;
      if (vx < 0 || vx > n - 1 || a[vx][vy] == 'M') {
        continue;
      }
      int ty = vy - 1;
      ty = (ty + m) % m;
      if (a[vx][ty] == 'M') {
        continue;
      }
      if (d[vx][ty] != -1) {
        continue;
      }      
      d[vx][ty] = d[ux][uy] + 1;
      que.push({vx, ty});
      if (vx == n - 1) {
        ans = min(ans, d[vx][ty] + 1);
        break;
      }
    }
    if (ans == INF) {
      int vx = ux, vy = uy;
      vy = (vy + m) % m;
      if (vx < 0 || vx > n - 1 || a[vx][vy] == 'M') {
        continue;
      }
      int ty = vy - 1;
      ty = (ty + m) % m;
      if (a[vx][ty] == 'M') {
        continue;
      }
      if (d[vx][ty] != -1) {
        continue;
      }      
      d[vx][ty] = d[ux][uy] + 1;
      que.push({vx, ty});
      if (vx == n - 1) {
        ans = min(ans, d[vx][ty] + 1);
        break;
      }
    }
  }
  dbg(d);
  cout << (ans == INF ? -1 : ans) << '\n';
}
