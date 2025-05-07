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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    bool ok = (x < y && x2 > y2) || (y < x && y2 > x2);
    cout << (ok ? "NO\n" : "YES\n");
  }
}


