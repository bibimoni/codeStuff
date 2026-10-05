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
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      x += a[i] & 1;
      if (a[i] % 2 == 0) {
        y += (a[i] / 2) & 1;
        z += 1 - ((a[i] / 2) & 1);
      }
    }

    cout << max({x, y, z}) << '\n';
  }
}
