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
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    if (n <= 4) {
      cout << "2\n";
      continue;  
    }
    int ans = 2;
    int cur = 4;
    while ((cur + 1) * 2 <= n) {
      ans += 1;
      cur = (cur + 1) * 2;
    }
    cout << ans + (cur < n) << '\n';
  }
}


