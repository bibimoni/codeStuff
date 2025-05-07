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
  int x, y;
  cin >> x >> y;
  x -= 1;
  y -= 1;
  vector<string> c(h);
  for (int i = 0; i < h; i++) {
    cin >> c[i];
  }
  string s;
  cin >> s;
  for (char i : s) {
    int ny = y + (i == 'L' ? -1 : (i == 'R' ? 1 : 0));
    int nx = x + (i == 'U' ? -1 : (i == 'D' ? 1 : 0));
    if (nx >= 0 && ny >= 0 && nx < h && ny < w && c[nx][ny] != '#') {
      x = nx;
      y = ny;
    }
  }
  cout << x + 1 << ' ' << y + 1 << '\n';
}


