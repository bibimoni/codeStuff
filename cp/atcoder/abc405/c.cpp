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
  int n;
  cin >> n;
  int sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i > 0) {
      ans += x * sum;
    }
    sum += x;
  }
  cout << ans << '\n';
}
