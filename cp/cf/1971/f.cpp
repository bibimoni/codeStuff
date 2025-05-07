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

const int N = (int) 1e5 + 5;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int r;
    cin >> r;
    double x1 = (double) sqrt(r * 2 + 1);
    if(x1 == (int) x1) {
      x1--;
    }
    else {
      x1 = (int) x1;
    }
    int ans = 4 + 8 * x1 - (x1 == r ? 4 : 0);
    cout << ans << '\n';

    dbg(x1);
  }
}


