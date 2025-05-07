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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, x0, y0, xD, yD;
    cin >> n >> m >> x0 >> y0 >> xD >> yD;
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    string d; cin >> d;
    int dX = (d[0] == 'D' ? 1 : -1);
    int dY = (d[1] == 'R' ? 1 : -1);
    int ans = 0; bool check = false;
    if(x0 == xD && y0 == yD) {check = true; cout << ans << '\n'; continue;}
    for(int i = 0; i < 4 * n * m; i++) {
      bool bounce = false;
      x0 += dX, y0 += dY;
      if(x0 == n + 1) {x0 -= 2, dX *= -1; bounce = true;}
      if(x0 == 0) {x0 += 2, dX *= -1; bounce = true;}
      if(y0 == m + 1) {y0 -= 2, dY *= -1; bounce = true;}
      if(y0 == 0) {y0 += 2, dY *= -1; bounce = true;}
      ans += bounce;
      if(x0 == xD && y0 == yD) {check = true; cout << ans << '\n'; break;}
    }
    if(!check) cout << "-1\n";
  }
}


