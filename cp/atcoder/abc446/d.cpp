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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, int> mp;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (mp.count(a[i] - 1)) {
      mp[a[i]] = max(mp[a[i]], mp[a[i] - 1] + 1);
    } else {
      mp[a[i]] = 1;
    }

    ans = max(ans, mp[a[i]]);
  }

  cout << ans << '\n';
}
