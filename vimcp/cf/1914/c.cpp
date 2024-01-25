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
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    int pre = 0, curr = b[1], ans = -1;
    for(int i = 1; i <= min(k, n); i++) {
      pre += a[i];
      curr = max(curr, b[i]);
      int sub = pre + (k - i) * curr;
      ans = max(ans, sub);
    }
    cout << ans << '\n';
  }
}


