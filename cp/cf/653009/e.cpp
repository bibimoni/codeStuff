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
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> id(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    id[p[i]] = i;
  }

  int ans = n, l = id[0], r = id[0];
  for (int mex = 1; mex < n; mex++) {
    int nxt = id[mex];
    dbg(l, r);
    if (l <= nxt && nxt <= r) {
      if ((mex < n - 1 && !(l <= id[mex + 1] && id[mex + 1] <= r))) {
        ans += mex;
      }
      continue;
    }

    if (nxt + 1 <= l) {
      // if (mex < n && !(l <= id[mex + 1] && id[mex + 1] <= r)) {
      // }
      ans += mex * (l - nxt);
      l = nxt;
    } else if (nxt - 1 >= r) {
      // if (mex < n && !(l <= id[mex + 1] && id[mex + 1] <= r)) {
      // }
      ans += mex * (nxt - r);
      r = nxt;
    }
    dbg(ans);
  }
  cout << ans << '\n';
}
