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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (a[i] % 6 == 0) {
        ans.push_back(a[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0 && a[i] % 3 != 0) {
        ans.push_back(a[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (a[i] % 2 != 0 && a[i] % 3 != 0) {
        ans.push_back(a[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (a[i] % 2 != 0 && a[i] % 3 == 0) {
        ans.push_back(a[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
}
