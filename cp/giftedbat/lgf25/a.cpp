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
    int n, x0;
    cin >> n >> x0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    __int128_t cur_x = 1e9;
    __int128_t cur_v = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      __int128_t dist = abs(a[i] - x0);
      if (dist * cur_v < cur_x * v[i]) {
        idx = i + 1;
        cur_x = dist;
        cur_v = v[i];
      }
    }
    assert(idx > 0);
    cout << idx << '\n';
  }
}
