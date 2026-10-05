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
  int ans = 0;

  auto ask = [&] (int i, int j) -> bool {
    cout << "? " << i << ' ' << j << '\n';
    cout.flush();
    string u;
    cin >> u;
    return u == "Yes";
  };

  int j = 1;
  for (int i = 1; i <= n; i++) {
    if (j < i) {
      j = i;
    }
    while (j + 1 <= n) {
      if (ask(i, j + 1)) {
        j += 1;
      } else {
        break;
      }
    }

    ans += j - i;
  }

  cout << "! " << ans << '\n';
}
