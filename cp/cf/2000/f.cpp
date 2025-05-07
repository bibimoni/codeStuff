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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      if (a[i].first > a[i].second) {
        swap(a[i].first, a[i].second);
      }
    }
    sort(a.begin(), a.end());

    auto calc = [&] (int cnt, int mn) -> int {
      int x = mn, y = mn;
      int ret = 0;
      while (cnt--) {
        if (x == y) {
          ret += x;
          x -= 1;
        } else if (x > y) {
          ret += y;
          x -= 1;
        } else {
          ret += x;
          y -= 1;
        }
      }
      return ret;
    };
    int ans = 0;
    for (int i = 0; k > 0 && i < n; i++) {
      auto [mn, mx] = a[i];
      int need = min(k, mx - mn);
      dbg(i, need, k);
      ans += mn * need;
      k -= need;
      if (k == 0) {
        break;
      }
      need = min(k, mn * 2 - 1);
      ans += calc(need, mn);
      k -= need;
    }
    cout << (k == 0 ? ans : -1) << '\n';
  }
}

