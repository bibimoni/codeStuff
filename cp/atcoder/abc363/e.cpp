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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int h, w, y;
  cin >> h >> w >> y;
  map<int, vector<pair<int, int>>> units;
  vector<vector<int>> a(h, vector<int>(w));
  int mn = int(1e9);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      units[a[i][j]].push_back({i, j});
      if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
        mn = min(mn, a[i][j]);
      }
    }
  }
  int cur = mn;
  queue<pair<int, int>> q;
  vector<vector<int>> was(h, vector<int>(w, 0));
  vector<pair<int, int>> last;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && a[i][j] <= cur) {
        last.push_back({i, j});
        was[i][j] = cur;
      }
    }
  }

  const vector<int> d = {-1, 0, 1, 0, -1};
  for (auto& l : last) {
    q.push(l);
  }
  vector<pair<int, int>> nxt;
  while (q.size()) {
    auto [ux, uy] = q.front();
    q.pop();      
    for (int i = 0; i < 4; i++) {
      int vx = ux + d[i];
      int vy = uy + d[i + 1];
      if (vx < 0 || vy < 0 || vx >= h || vy >= w) {
        continue;
      }
      if (was[vx][vy] || a[vx][vy] > cur) {
        continue;
      }
      q.push({vx, vy});
      was[vx][vy] = cur;
      nxt.push_back({vx, vy});
    }
  }
  swap(last, nxt);
  for (int ys = mn; ys < y; ys++) {
    cur += 1;
    for (auto l : last) {
      q.push(l);
      auto [x, y] = l;
      if (!was[x][y] && a[x][y] >= cur) {
        was[x][y] = cur; 
      }
    }
    for (auto l : units[cur]) {
      q.push(l);      
      auto [x, y] = l;
      if (!was[x][y] && a[x][y] >= cur) {
        was[x][y] = cur; 
      }
    }
    vector<pair<int, int>> nxt;
    while (q.size()) {
      auto [ux, uy] = q.front();
      q.pop();      
      for (int i = 0; i < 4; i++) {
        int vx = ux + d[i];
        int vy = uy + d[i + 1];
        if (vx < 0 || vy < 0 || vx >= h || vy >= w) {
          continue;
        }
        if (was[vx][vy] || a[vx][vy] > cur) {
          continue;
        }
        q.push({vx, vy});
        was[vx][vy] = cur;
        nxt.push_back({vx, vy});
      }
    }
    swap(last, nxt);
  }
  vector<int> ans(y);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (was[i][j] == 0) {
        continue;
      }
      ans[was[i][j] - 1] += 1;
    }
  }
  for (int i = 0; i < y; i++) {
    if (i > 0) {
      ans[i] += ans[i - 1];
    }
    cout << h * w - ans[i] << '\n';
  }
}


