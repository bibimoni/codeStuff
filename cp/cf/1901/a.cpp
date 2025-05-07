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
    int n, x; cin >> n >> x;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    int ans = a[0];
    for(int i = 0; i < n - 1; i++) {
      ans = max(ans, a[i + 1] - a[i]);
    }
    ans = max(ans, 2 * (x - a[n - 1]));
    cout << ans << '\n';
  }
}


