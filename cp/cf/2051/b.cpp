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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = n / (a + b + c);
    int cur = ans * (a + b + c);
    ans *= 3;
    if (cur < n) {
      cur += a;
      ans += 1;
    }
    if (cur < n) {
      cur += b;
      ans += 1;
    }
    if (cur < n) {
      cur += c;
      ans += 1;
    }
    cout << ans << '\n';
  }
}


