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
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = a[0], curr = a[0]; bool od = a[0] & 1;
    for(int i = 1; i < n; i++) {
      if(curr + a[i] > a[i] && ((a[i] % 2 == 0 && od)||(a[i] % 2 != 0 && !od))) {
        curr += a[i];
        od = a[i] & 1;
      }
      else {
        curr = a[i];
        od = a[i] & 1;
      }
      ans = max(ans, curr);
    }
    cout << ans << '\n';
    //dbg('a');
  }
}


