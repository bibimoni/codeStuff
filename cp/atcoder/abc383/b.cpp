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
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  auto get = [&] (pair<int, int> pos1, pair<int, int> pos2) -> int {
    int ret = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (a[i][j] == '#') {
          continue;
        }
        if (abs(i - pos1.first) + abs(j - pos1.second) <= d || abs(i - pos2.first) + abs(j - pos2.second) <= d) {
          ret += 1;
        }
      }
    }
    return ret;
  };
  int ans = 0;
  for (int i1 = 0; i1 < h; i1++) {
    for (int j1 = 0; j1 < w; j1++) {
      for (int i2 = 0; i2 < h; i2++) {
        for (int j2 = 0; j2 < w; j2++) {
          if (i1 == i2 && j1 == j2) {
            continue;
          }
          if (a[i1][j1] == '#' || a[i2][j2] == '#') {
            continue;
          }
          // dbg(i1, j1, i2, j2, get({i1, j1}, {i2, j2}));
          ans = max(ans, get({i1, j1}, {i2, j2}));
        }
      }
    }
  }
  cout << ans << '\n';
}


