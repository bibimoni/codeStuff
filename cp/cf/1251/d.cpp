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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
      s -= a[i].first;
    }
    sort(a.begin() + 1, a.end(), [&] (pair<int, int> &i, pair<int, int> &j) {
      return i.first < j.first;
    });
    int l = 0, r = int(1e9);
    int ans = l;
    while (l <= r) {
      int m = (l + r) >> 1;
      int req = n / 2 + 1;
      int curr = s;
      for (int i = n; req > 0 && i >= 1; i--) {
        auto [tl, tr] = a[i];
        if(tr >= m) {
          curr -= max(0ll, m - tl);
          req -= 1;
        }
      }
      if (curr >= 0 && req == 0) {
        l = m + 1;
        ans = m;
      } else {
        r = m - 1;
      }
    }
    cout << ans << '\n';
  }
}

