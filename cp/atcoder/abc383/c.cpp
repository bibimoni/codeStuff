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

const vector<int> dir{-1, 0, 1, 0, -1};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  vector<vector<int>> was(h, vector<int>(w, 0));
  queue<array<int, 3>> que;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == 'H') {
        que.push({0, i, j});
      }
    }
  }
  while (que.size()) {
    auto p = que.front();
    que.pop();
    int step = p[0], ux = p[1], uy = p[2];
    if (was[ux][uy]) {
      continue;
    }
    was[ux][uy] = 1;
    for (int k = 0; k < 4; k++) {
      int vx = ux + dir[k];
      int vy = uy + dir[k + 1];
      if (vx < 0 || vy < 0 || vx >= h || vy >= w || a[vx][vy] != '.' || step + 1 > d) {
        continue;
      }
      que.push({step + 1, vx, vy});
    }
  }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ans += was[i][j] > 0;
    }
  }
  cout << ans << '\n';
}


