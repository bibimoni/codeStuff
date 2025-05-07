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
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a * b * c;
    for (int i = 0; i <= 5; i++) {
      for (int j = 0; j <= 5; j++) {
        for (int k = 0; k <= 5; k++) {
          if (i + j + k <= 5) {
            ans = max(ans, (a + i) * (b + j) * (c + k));
          }
        }
      }
    }
    cout << ans << '\n';
  }
}


