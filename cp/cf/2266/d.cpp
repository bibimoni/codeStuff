/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b[i] = x - i;
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int ans = 1, cur = 1;
    for (int i = 1; i < n; i++) {
      if (b[i] == b[i - 1] + 1) {
        cur += 1;
      } else {
        cur = 1;
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}
