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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  string t;
  cin >> t;
  vector<string> a(h);
  for(int i = 0; i < h; i++) {
    cin >> a[i];
  }
  auto perform = [&] (int x, int y) {
    for(int i = 0; i < n; i++) {
      if(t[i] == 'L') y--;
      else if(t[i] == 'R') y++;
      else if(t[i] == 'U') x--;
      else x++;
      if(!(x >= 0 && y >= 0 && x < h && y < w && a[x][y] == '.')) {
        return false;
      } 
    }
    return true;
  };
  int ans = 0;
  for(int i = 1; i < h - 1; i++) {
    for(int j = 1; j < w - 1; j++) {
      if(a[i][j] == '.') {
        ans += (int) perform(i, j);
      }
    }
  }
  cout << ans;
}


