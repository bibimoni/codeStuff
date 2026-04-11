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
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int lo = 0, hi = i, ret = -1;
        while (lo <= hi) {
          int mid = (lo + hi) >> 1;
          // 2 option, pick largest or pick current item? (I am not chatgpt lol)
          if (a[mid] + a[i] > a[j] &&
              a[mid] + a[i] + (j == n - 1 ? 0 : a[j]) > a[n - 1]) {
            hi = mid - 1;
            ret = mid;
          } else {
            lo = mid + 1;
          }
        }
        if (ret != -1) {
          ans += i - ret;
        }
      }
    }

    cout << ans << '\n';
  }
}
