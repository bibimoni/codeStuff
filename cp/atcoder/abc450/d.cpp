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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= k;
  }
  sort(a.begin(), a.end());
  int ans = a[n - 1] - a[0];
  for (int i = 0; i + 1 < n; i++) {
    ans = min(ans, a[i] + k - a[i + 1]);
  }
  cout << ans << '\n';
}
