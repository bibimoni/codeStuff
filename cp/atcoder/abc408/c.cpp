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
  int n, m;
  cin >> n >> m;
  vector<int> pref(n + 2);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    pref[l] += 1;
    pref[r + 1] -= 1;
  }

  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    pref[i] += pref[i - 1];
    ans = min(ans, pref[i]);
  }
  cout << ans << '\n';
}
