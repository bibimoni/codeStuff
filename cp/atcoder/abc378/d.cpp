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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  auto calc = [&] (auto &&self, int x, int y, set<pair<int, int>>& st) -> int {
    if (st.size() == k + 1) {
      return 1;
    }
    int ret = 0;
    const vector<int> dir{-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int px = x + dir[i];
      int py = y + dir[i + 1];
      if ((px < 0) || (py < 0) || (px >= h) || (py >= w) || (a[px][py] == '#') || st.find({px, py}) != st.end()) {
        continue;
      }
      st.insert({px, py});
      ret += self(self, px, py, st);
      st.erase({px, py});
    }
    return (memo[{x, y, (int)st.size()}] = ret);
  };  

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        continue;
      }
      set<pair<int, int>> st;
      st.insert({i, j});
      ans += calc(calc, i, j, st);
    }
  }
  cout << ans;
}


