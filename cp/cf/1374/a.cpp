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
    int x, y, n;
    cin >> x >> y >> n;
    int mul = (n / x) * x;
    while(mul + y > n) {
      mul -= x;
    }
    cout << mul + y << '\n';
  }
}


