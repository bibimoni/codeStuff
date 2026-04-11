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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());

  int ans = a[0];
  int cur = a[0];
  for (int i = 1; i < n; i++) {
    cur += a[i];
    if (i % 2 == 0) {
      ans = max(ans, cur);
    }
  }

  cout << ans << "\n";
}
