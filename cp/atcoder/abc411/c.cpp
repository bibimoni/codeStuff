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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  int cur = 0;
  if (n == 1) {
    while (q--) {
      int x;
      cin >> x;
      x -= 1;
      a[x] ^= 1;
      cout << a[x] << '\n';
    }
    return 0;
  }
  while (q--) {
    int x;
    cin >> x;
    x -= 1;
    if (x == 0) {
      int s = -(a[x] == 1) - (a[x] == 0 && a[x + 1] == 1);
      a[x] ^= 1;
      int ss = (a[x] == 1) + (a[x] == 0 && a[x + 1] == 1);
      cur += s + ss;
    } else {
      int s = -(a[x - 1] == 0 && a[x] == 1) - (a[x] == 0 && a[x + 1] == 1);
      a[x] ^= 1;
      int ss = (a[x - 1] == 0 && a[x] == 1) + (a[x] == 0 && a[x + 1] == 1);
      cur += s + ss;
    }
    cout << cur << '\n';
  }
}
