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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >>tt;
  while(tt--) {
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int k = 1; k <= n; k++) {
      if(n % k != 0) continue;
      int maxW = 0, minW = 0, curr = 0;
      for(int i = 0; i < k; i++) {
        curr += a[i]; 
      }
      maxW = minW = curr;
      curr = 0;
      for(int i = k; i < n; i++) {
        curr += a[i];
        if((i + 1) % k == 0) {
          maxW = max(maxW, curr);
          minW = min(minW, curr);
          curr = 0;
        }
      }
      ans = max(ans, maxW - minW);
    }
    cout << ans << '\n';
  }
}


