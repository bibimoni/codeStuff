#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minMoves(vector<string> &a) {
    int n = a.size();
    int m = a[0].size();
    const int INF = 1e9;
    const vector<int> dir{-1, 0, 1, 0, -1};
    vector<set<pair<int, int>>> ll(26);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != '.' && a[i][j] != '#') {
          ll[a[i][j] - 'A'].insert({i, j});
        }
      }
    }
    auto dijkstra = [&]() -> vector<vector<int>> {
      set<array<int, 3>> que;
      que.insert({0, 0, 0});
      vector<vector<int>> d(n, vector<int>(m, INF));
      d[0][0] = 0;
      while (que.size()) {
        auto p = *que.begin();
        int ux = p[1], uy = p[2], uw = p[0];
        que.erase(que.begin());
        if (d[ux][uy] != uw) {
          continue;
        }
        if (a[ux][uy] != '.' && a[ux][uy] != '#') {
          for (auto [vx, vy] : ll[a[ux][uy] - 'A']) {
            if (d[vx][vy] > d[ux][uy]) {
              was[vx][vy] = 1;
              d[vx][vy] = uw;
              que.insert({d[vx][vy], vx, vy});
            }
          }
          ll[a[ux][uy] - 'A'].clear();
        }
        for (int k = 0; k < 4; k++) {
          int vx = ux + dir[k];
          int vy = uy + dir[k + 1];
          if (vx < 0 || vy < 0 || vx >= n || vy >= m || a[vx][vy] == '#') {
            continue;
          }
          if (d[vx][vy] > d[ux][uy] + 1) {
            d[vx][vy] = d[ux][uy] + 1;
            que.insert({d[vx][vy], vx, vy});
          }
        }
      }
      return d;
    };
    auto d = dijkstra();
    return (d[n - 1][m - 1] >= INF ? -1 : d[n - 1][m - 1]);
  }
};
