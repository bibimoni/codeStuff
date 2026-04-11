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
    auto ask = [&](int x, int l, int r) -> int {
      cout << x << ' ' << l << ' ' << r << '\n';
      cout.flush();
      int v;
      cin >> v;
      return v;
    };

    int lo = 1, hi = n, rl = 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      int org = ask(1, 1, mid), mod = ask(2, 1, mid);
      if (org == mod) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
        rl = mid;
      }
    }
    int rr = rl + (ask(2, rl, n) - ask(1, rl, n)) - 1;
    cout << "! " << rl << ' ' << rr << '\n';
    cout.flush();
  }
}
