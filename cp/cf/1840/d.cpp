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
    sort(a.begin(), a.end());
    int l = 0, r = int(1e9), ans = r;
    while (l <= r) {
      int m = (l + r) >> 1, cnt = 0;
      for (int i = 0, j = 0; i < n; i++) {
        if (a[i] - a[j] > 2 * m) {
          cnt += 1;
          j = i;
        }
      }
      if (cnt >= 3) {
        l = m + 1;
      } else {
        r = m - 1;
        ans = m;
      }
    }
    cout << ans << '\n';
  }
}

