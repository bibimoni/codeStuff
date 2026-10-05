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
  vector<int> c(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    c[x - 1] += 1;
  }

  int ans = n - *max_element(c.begin(), c.end());
  cout << ans << '\n';
}
