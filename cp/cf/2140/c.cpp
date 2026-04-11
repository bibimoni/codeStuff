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
    vector<int> a(n);
    int s1 = 0, s2 = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i % 2 == 0) {
        last = i;
        s1 += a[i];
      } else {
        s2 += a[i];
      }
    }

    int ans = s1 - s2 + (n >= 3 ? last : 0);
    set<pair<int, int>, greater<pair<int, int>>> st1, st2;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (st2.size()) {
          int v = -2 * a[i] + i;
          auto [v2, id2] = *st2.begin();
          ans = max(ans, s1 - s2 + v + v2);
        }
        st1.insert({-2 * a[i] - i, i});
      } else {
        if (st1.size()) {
          int v = 2 * a[i] + i;
          auto [v1, id1] = *st1.begin();
          ans = max(ans, s1 - s2 + v + v1);
        }
        st2.insert({2 * a[i] - i, i});
      }
    }

    cout << ans << "\n";
  }
}
