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
    int n;
    cin >> n;
    int ans = 0, ret = 1;
    for(int i = 1; i < n; i++) {
      if(ans <  __gcd(n, i) + i) {
        ans = __gcd(n, i) + i;
        ret = i;
      }
    }
    cout << ret << '\n';
  }
}


