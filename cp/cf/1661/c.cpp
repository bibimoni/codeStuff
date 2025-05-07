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
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> h[i];
    }
    int hmx = *max_element(h.begin() + 1, h.end());
    function<int(int)> ans = [&] (int mx) -> int {
      int lo = 0, hi = 1e18, ret = 1e18;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int c2 = mid / 2, c1 = mid - c2;    
        auto b = h;
        for (int i = 1; i <= n; i++) {
          int need = (mx - b[i]) / 2;
          need = min(need, c2);
          c2 -= need;
          b[i] += need * 2;
          need = min(mx - b[i], c1);
          c1 -= need;
          b[i] += need;
        }
        bool is_full = true;
        for (int i = 1; i <= n; i++) {
          is_full &= b[i] == mx;
        }
        if (is_full) {
          hi = mid - 1;
          ret = mid;
        } else {
          lo = mid + 1;
        }
      }
      return ret;
    };
    cout << min(ans(hmx), ans(hmx + 1)) << '\n';
  }
}

