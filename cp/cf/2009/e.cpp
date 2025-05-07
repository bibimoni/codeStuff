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
    auto range = [&] (int l, int r) -> int {
      if (l > r) {
        return 0;
      }
      return (r * (r + 1) - l * (l - 1)) / 2;
    };
    int c = -(k * k) + k - k * n - (n * n) / 2 + (n / 2);
    dbg(c);
    int i = (-1 + sqrt(1 - 4 * c)) / 2;
    // int i = n - sqrt(n) + k;
    int ans = LLONG_MAX;
    dbg(i);
    for (int x = max(k, i - 5); x <= min(k + n - 1, i + 5); x++) {
      ans = min(ans, abs(range(k, x) - range(x + 1, k + n - 1)));
      dbg(x, ans, range(k, x), range(x + 1, k + n - 1));
    }
    cout << ans << '\n';
  }
}


