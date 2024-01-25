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
  int tt;
  cin >> tt;
  while(tt--) {
    int x = 1001, y = 1001, x2 = -1001, y2 = -1001;
    for(int i = 0; i < 4; i++) {
      int tx, ty; cin >> tx >> ty;
      x = min(tx, x);
      y = min(ty, y);
      x2 = max(tx, x2);
      y2 = max(ty, y2);
    }
    cout << (x2 - x) * (y2 - y) << '\n';
  }
}


