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
  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1);
  set<int> pos;
  int xr = 0;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x;
      cin >> x;
      int old = a[x], nw = old + 1;
      xr ^= old ^ nw;
      a[x] = nw;
      if (old == 0) {
        pos.insert(x);
      }
    } else {
      for (auto it = pos.begin(); it != pos.end();) {
        int i = *it;
        int old = a[i], nw = old - 1;
        xr ^= old ^ nw;
        a[i] = nw;
        if (nw == 0) {
          it = pos.erase(it);
        }
        else ++it;
      }
    }
    cout << xr << '\n';
  }
}
