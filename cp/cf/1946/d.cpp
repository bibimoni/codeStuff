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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    x += 1;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] ^ a[i];
    }
    int ans = -1;
    for (int j = 0; j <= 30; j++) {
      if ((x >> j) & 1) {
        int target = x ^ (1ll << j);
        int t = (1ll << j) - 1;
        target |= t;
        if ((p[n] & target) != p[n]) {
          continue;
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
          if ((p[i] & target) == p[i]) {
            cur += 1;
          }
        }
        ans = max(ans, cur);
      }
    }
    cout << ans << '\n';
  }
}


