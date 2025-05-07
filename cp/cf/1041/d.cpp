/**
 * Author: distiled
 */
#include<bits/stdc++.h>
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
  int n, h;
  cin >> n >> h;
  vector<pair<int, int>> x(n);
  vector<int> des(n);
  des[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i].first >> x[i].second;
    if (i > 0) {
      des[i] = des[i - 1] + x[i].first - x[i - 1].second;
    }
  }
  auto dist = [&](int l, int r) -> int {
    return x[r].first - x[l].first;
  };
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int l = i, r = n - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      int lost = des[m] - des[i];
      if (h - lost < 0) {
        r = m - 1;
      } else {
        int d = dist(i, m);
        if (h - lost > 0) {
          d += x[m].second - x[m].first + h - lost;
        }
        ans = max(ans, d);
        l = m + 1;
      }
    }
  }
  cout << ans << '\n';
}

