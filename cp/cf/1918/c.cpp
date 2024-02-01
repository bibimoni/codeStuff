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
    int a, b, r;
    cin >> a >> b >> r;
    if(b > a) swap(a, b);
    int diff = a - b, rev = diff;
    int number = 0;
    for(int i = 60; i >= 0; i--) {
      int ca = (a >> i) & 1, cb = (b >> i) & 1;
      if(ca == 1 && cb == 0 && (number | (1ll << i)) <= r) {
        if(diff >= 2 * (1ll << i)) {
          number |= (1ll << i);
          diff -= 2 * (1ll << i);
        }
        else {
          rev = min(rev, 2 * (1ll << i) - diff);
        }
      }
    }
    cout << min(diff, rev) << '\n';
  }
}


