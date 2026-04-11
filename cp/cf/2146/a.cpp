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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a;
    int prev = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x != prev) {
        if (prev != 0) {
          a.push_back(cnt);
        }
        prev = x;
        cnt = 1;
      } else {
        cnt += 1;
      }
    }

    a.push_back(cnt);
    int ans = 0;
    sort(a.begin(), a.end());
    n = int(a.size());
    for (int i = 0; i < n; i++) {
      ans = max(ans, a[i] * (n - i));
    }

    cout << ans << '\n';
  }
}
