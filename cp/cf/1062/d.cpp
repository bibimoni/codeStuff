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
  int64_t ans = 0;
  vector<int> was(n + 1);
  for (int i = 2; i <= n; i++) {
    for (int j = i * 2; j <= n; j += i) {
      ans += 4 * (j / i);
    }
  }

  cout << ans << '\n';
}
