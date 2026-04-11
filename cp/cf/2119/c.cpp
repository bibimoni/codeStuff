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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 1) {
      cout << l << '\n';
    } else {
      int j = -1;
      for (int i = 0; i < 60; i++) {
        int last2 = (int(1) << i);
        if (last2 >= l && last2 <= r && (last2 & l) == 0) {
          j = last2;
          break;
        }
      }
      if (j == -1 || n == 2) {
        cout << "-1\n";
      } else {
        if (k >= n - 1) {
          cout << j << '\n';
        } else {
          cout << l << '\n';
        }
      }
    }
  }
}
