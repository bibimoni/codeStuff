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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k, x; cin >> n >> k >> x;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int pref[n + 1]; pref[0] = 0;
    for(int i = 1; i <= n; i++) {
      pref[i] = pref[i  - 1] + a[i];
    }
    int ans = -INF;
    for(int i = 0; i <= min(n, k); i++) {
      int bob = -(pref[min(i + x, n)] - pref[i]);
      int alice = pref[n] - pref[min(i + x, n)];
      ans = max(ans, bob + alice);
    }    
    cout << ans << '\n';
  }
}


