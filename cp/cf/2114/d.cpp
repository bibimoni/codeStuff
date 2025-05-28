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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    multiset<int> xs, ys;
    for (int i = 0; i < n; i++) {
      cin >> p[i].first >> p[i].second;
      xs.insert(p[i].first);
      ys.insert(p[i].second);
    }
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    const int INF = 2e18;
    int ans = INF;
    for (int i = 0; i < n; i++) {
      auto [x, y] = p[i];
      xs.erase(xs.find(x));
      ys.erase(ys.find(y));
      int mn_x = *xs.begin();
      int mn_y = *ys.begin();
      int mx_x = *xs.rbegin();
      int mx_y = *ys.rbegin();
      int w = mx_x - mn_x + 1;
      int h = mx_y - mn_y + 1;
      if (h * w == n - 1) {
        ans = min(ans, h * w + min(h, w));
      } else {
        ans = min(ans, h * w);
      }
      xs.insert(x);
      ys.insert(y);
    }
    cout << ans << '\n';
  }
}
