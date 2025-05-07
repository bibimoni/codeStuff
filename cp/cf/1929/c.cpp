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
    int k, x, a;             
    cin >> k >> x >> a;
    int neg = 0;
    for(int i = 1; i <= x; i++) {
      neg += (neg + k - 1) / (k - 1) + ((neg + k - 1) < (k - 1));
      if(neg > a) {
        break;
      }
    }
    cout << ((k * (a - neg) > a) ? "YES\n" : "NO\n");
  }
}


