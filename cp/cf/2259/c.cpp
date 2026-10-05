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
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }

    int l = 0;
    while (l < n) {
      if (a[l] == 1 || a[l] == -1) {
        a[l] = 1;
        break;
      }
      l += 1;
    }
    int r = n - 1;
    while (r >= 0) {
      if (a[r] == 1 || a[r] == -1) {
        a[r] = 1;
        break;
      }
      r -= 1;
    }
    
    for (int i = 0; i < n; i++) {
      if (a[i] == -1) {
        a[i] = 0;
      }
      cout << a[i] << " \n"[i == n -1];
    }
  }
}
