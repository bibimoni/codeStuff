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
  int tt;
  cin >> tt;
  while (tt--) {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    for (int a : {a1, a2}) {
      for (int b : {b1, b2}) {
        int sa = (a1 + a2) - a;
        int sb = (b1 + b2) - b;
        int ca = (a > b) + (sa > sb);
        int cb = (b > a) + (sb > sa);
        ans += (ca > cb);
      }
    }
    cout << ans << '\n';
  }
}


