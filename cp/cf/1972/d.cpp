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
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int b = 1; b <= m; b++) {
      for(int a = b; a <= n; a += b) {
        if((a + b) % (b * __gcd(a, b)) == 0) {
          ans++;
        }  
      }
    }
    cout << ans << '\n';
  }
}


