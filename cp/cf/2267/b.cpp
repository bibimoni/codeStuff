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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> cnt(101);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x] += 1;
    }

    while (n) {
      for (int i = 100; i >= 1; i--) {
        if (cnt[i] > 0) {
          cnt[i] -= 1;
          cout << i << " \n"[n == 1];
          n -= 1;
        }
      }
    }
  }
}
