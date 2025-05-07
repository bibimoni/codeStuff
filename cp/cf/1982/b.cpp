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
  while (tt--) {
    int x, y, k;
    cin >> x >> y >> k;
    while (k > 0 && x > 1) {
      int bound = (x / y) * y;
      while (bound <= x) {
        bound += y;
      }
      int t = min(bound - x, k);
      k -= t;
      x += t;    
      while (x % y == 0) {
        x /= y;
      }
    }
    if (x == 1) {
      x += (k % (y - 1));
    }
    while (x % y == 0) {
      x /= y;
    }
    cout << x << '\n';
  }
}


