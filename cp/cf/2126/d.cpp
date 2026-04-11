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
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> a(n);
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
      int l, r, v;
      cin >> l >> r >> v;
      a[i] = {l, r, v};
      mp[l].push_back({v, r});
    }

    sort(a.begin(), a.end());

    int cur = k;
    for (int i = 0; i < n; i++) {
      if (a[i][0] <= cur && cur <= a[i][1]) {
        cur = max(cur, a[i][2]);
      }
    }
    cout << cur << '\n';
  }
}
