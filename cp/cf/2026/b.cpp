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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    if (n % 2 == 0) {
      int ans = 0;
      for (int i = 0; i < n; i += 2) {
        ans = max(ans, a[i + 1] - a[i]);
      }
      cout << ans << '\n';
      continue;
    }
    // dbg(a);
    int ans = 1e18;
    for (int iter = 0; iter < n; iter++) {
      int cur = 0;
      bool can = true;
      for (int i = 0; i < n; ) {
        if (i == iter) {
          i += 1;
          continue;
        }
        if (i + 1 >= n) {
          can = false;
          break;
        }
        cur = max(cur, a[i + 1] - a[i]);
        i += 2;
      }
      if (can) {
        ans = min(ans, cur);
      }
      // dbg(b);
    }
    cout << ans << '\n';
  }
}


