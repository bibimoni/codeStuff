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
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  x -= 1;
  y -= 1;
  set<pair<int, int>> st;
  string t;
  cin >> t;
  for (char c : t) {
    if (a[x][y] == '@') {
      st.insert({x, y});
    }
    pair<int, int> off;
    if (c == 'U') {
      off = {-1, 0};
    } else if (c == 'D') {
      off = {1, 0};
    } else if (c == 'L') {
      off = {0, -1};
    } else if (c == 'R') {
      off = {0, 1};
    }
    int vx = x + off.first;
    int vy = y + off.second;
    if (vx < 0 || vy < 0 || vx >= h || vy >= w || a[vx][vy] == '#') {
      continue;
    }
    x = vx;
    y = vy;
  }
  if (a[x][y] == '@') {
    st.insert({x, y});
  }
  cout << x + 1 << ' ' << y + 1 << ' ' << st.size();
}


