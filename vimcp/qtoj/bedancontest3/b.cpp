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
    int n; cin >> n;
    int a = sqrt(n);
    //int ans = m * a - (a * a * a) / int(3) - (a * a) / int(2) + (int(5) * a) / int(6);
    long double block1 = ((2 * a + 5) * (a - 1)) / 6.0;
    dbg(block1);
    int ans = a * (n - block1);
    cout << ans << '\n';    
  }
}


