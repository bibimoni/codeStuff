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
  vector<int> ans = {0, 1, 2, 2, 3, 3, 4};
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n <= 6) {
      cout << ans[n] << '\n';
      for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
      }
    } else {
      cout << "4\n";
      for (int cur = 0, i = 1; i <= n; i++) {
        cout << cur + 1 << " \n"[i == n];
        (cur += 1) %= 4;
      }
    }
  }
}


