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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  int xs, ys, xe, ye;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'G') {
        xe = i, ye = j;
      } else if (s[i][j] == 'S') {
        xs = i, ys = j;
      }
    }
  }

  auto valid = [&] (int x, int y) -> bool {
    return x >= 0 && y >= 0 && x < h && y < w && s[x][y] != '#';
  };

  set<array<int, 4>> st;
  st.insert({0, 0, xs, ys});
  st.insert({0, 1, xs, ys});
  const int INF = numeric_limits<int>::max();
  array<vector<vector<int>>, 2> d;
  d[0] = vector(h, vector(w, INF));
  d[1] = vector(h, vector(w, INF));
  d[0][xs][ys] = 0;
  d[1][xs][ys] = 0;

  while (st.size()) {
    auto p = *st.begin();
    st.erase(st.begin());
    int w = p[0], x = p[1], ux = p[2], uy = p[3];
    if (d[x][ux][uy] != w) {
      continue;
    }
    for (int diff : {-1, 1}) {
      int vx, vy;
      if (x == 0) {
        vx = ux + diff;
        vy = uy;
      } else {
        vx = ux;
        vy = uy + diff;
      }
      if (!valid(vx, vy)) {
        continue;
      }
      if (d[1 ^ x][vx][vy] > d[x][ux][uy] + 1) {
        d[1 ^ x][vx][vy] = d[x][ux][uy] + 1;
        st.insert({d[1 ^ x][vx][vy], 1 ^ x, vx, vy});
      }
    }
  }
  int ans = min(d[0][xe][ye], d[1][xe][ye]);
  cout << (ans == INF ? -1 : ans);
}


