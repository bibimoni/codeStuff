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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
    }
    cout << n + m << '\n';
  }
}
