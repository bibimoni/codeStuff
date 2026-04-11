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
  int n, c1, c2;
  cin >> n >> c1 >> c2;
  vector<string> a(n);
  vector<int> same(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sort(a[i].begin(), a[i].end());
    same[i] = int(a[i][0] == a[i][1] || a[i][1] == a[i][2]);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (same[i]) {
      ans += min(2 * c1, c2);
      ans += min(c1, c2);
    } else {
      ans += min(c1, c2) * 3;
    }
  }

  cout << ans << '\n';
}
