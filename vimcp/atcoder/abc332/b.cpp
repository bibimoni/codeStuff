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
  int k, g, m; cin >> k >> g >> m;
  int tg = 0, tm = 0;
  for(int i = 0; i < k; i++) {
    if(tg == g) tg = 0;
    else if(tm == 0) tm = m;
    else {
      int prev = tg;
      tg = min(tm, g);
      tm -= min(tm, g) - prev;
    }
    dbg(tg, tm);
  }
  cout << tg << ' ' << tm;
}


