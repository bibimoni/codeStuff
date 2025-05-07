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
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int a = 1; a <= x; a++) {
      for (int b = 1; b <= x; b++) {
        if (x - a - b <= 0) {
          break;
        }
        if (a * b + 2 > n) {
          break;
        }
        int c = (n - a * b) / (a + b);
        if (c <= 0) {
          continue;
        }
        ans += min(c, x - a - b);
      } 
    }
    cout << ans << '\n';
  }
}


