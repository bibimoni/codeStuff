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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> cur;
    int ans = 0;
    for (int i = n; k > 0 && i >= 1; i--) {
      if (i == n) {
        k -= i;
        ans += 1;
      } else {
        k -= i;
        ans += 1;
        if (k > 0) {
          k -= i;
          ans += 1;
        }
      }
    }
    cout << ans << '\n';
  }
}


