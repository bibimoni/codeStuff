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
    int n, k; cin >> n >> k;
    int a[n];
    /*
    x + y = z + const
    x' + y' = z' (make the constant gone).
    x' = x + d, y' = y + d, z' = z + d
    x' + y' = z'
    -> x' + y' = x + y + 2d = z + 2d + const = z' + d + const
    -> d + const = 0 => d = -const = -k 
    => x' = x - k
    subtract k from all numbers then the problem becomes x + y = z.
    where we remove z and add x, y into the multiset
    */
    bool allZeros = true, allPos = true, allNeg = true;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] -= k;
      if(a[i] != 0) allZeros = false;
      if(a[i] >= 0) allNeg = false;
      if(a[i] <= 0) allPos = false;
    }    
    if(allZeros) {
      cout << "0\n";
    }
    //can't both have negative and positive 
    else if((int) !allPos + (int) !allNeg >= 2) {
      cout << "-1\n";
    }
    else {
      int g = allPos ? a[0] : -a[0];
      for(int i = 1; i < n; i++) {
        g = __gcd(g, (allPos ? a[i] : -a[i]));
      }
      int ans = 0;
      g = (allPos ? g : -g);
      for(int i = 0; i < n; i++) {
        ans += a[i] / g - 1;
      }
      cout << ans << '\n';
    }
  }
}


