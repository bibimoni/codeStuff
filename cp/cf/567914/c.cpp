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
  const int INF = 1e18;
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> robots;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == -1) {
        robots.push_back({i, j});
      }
    }
  }
  const vector<int> dir_x = {0, 0, 1, -1, 1, -1, 1, -1};
  const vector<int> dir_y = {1, -1, 0, 0, 1, -1, -1, 1};

  auto dijkstra = [&] (int x, int y) -> vector<vector<int>> {
    vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));
    d[x][y] = int(0);
    multiset<array<int, 3>> st;
    st.insert({0, x, y});
    while (st.size()) {
      auto p = *st.begin();
      int w = p[0], ux = p[1], uy = p[2];
      st.erase(st.begin());
      if (d[ux][uy] != w) {
        continue;
      }
      for (int i = 0; i < 8; i++) {
        int vx = dir_x[i] + ux;
        int vy = dir_y[i] + uy;
        if (!(vx >= 1 && vy >= 1 && vx <= n && vy <= m)) {
          continue;
        }
        int nd = max(d[ux][uy] + 1, (a[vx][vy] == -1 ? 0 : a[vx][vy]));
        if (d[vx][vy] > nd) {
          d[vx][vy] = nd;
          st.insert({nd, vx, vy});
        }
      }
    }
    return d;
  };
  vector<vector<vector<int>>> di(k);
  int idx = 0;
  for (auto [x, y] : robots) {
    di[idx] = dijkstra(x, y);
    idx += 1;
  }
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cur = 0;
      for (int p = 0; p < k; p++) {
        cur = max(cur, di[p][i][j]);
      }
      ans = min(ans, cur);
    }
  }
  cout << ans << '\n';
}

