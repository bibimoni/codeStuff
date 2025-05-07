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
    int h, n;
    cin >> h >> n;
    int sa = 0;
    vector<int> a(n + 1); 
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      sa += a[i];
    }
    vector<int> c(n + 1);
    int sc = 0;
    for(int i = 1; i <= n; i++) {
      cin >> c[i];
      sc += c[i];
    }
    int r;
    if(sa < sc) {
      r = (int) 1e18;
    }
    else {
      r = (int) 1e18 / sa * sc + 100;
    }
    int l = 1, ans = 1e18;
    dbg(r);
    while(l <= r) {
      int m = (l + r) >> 1;
      int dmg = sa;
      bool ok = true;
      for(int i = 1; i <= n; i++) {
        if(dmg > 1e18 - a[i] * ((m - 1) / c[i])) {
          ok = false;
          break;
        }
        dmg += a[i] * (((m - 1) / c[i]));
      }
      if(dmg >= h || (!ok)) {
        r = m - 1;
        if(ok)
          ans = m;
      }
      else {
        l = m + 1;
      }
    }
    cout << ans << '\n';
  }
}


