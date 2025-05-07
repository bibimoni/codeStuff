// time-limit: 3000
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), int(0));
    sort(a.begin(), a.end());
    int lb = sum - y, rb = sum - x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int it1 = lower_bound(a.begin(), a.end(), lb - a[i]) - a.begin();
      auto it2 = upper_bound(a.begin(), a.end(), rb - a[i]);
      if (it2 == a.begin()) {
        continue;
      }
      it2--;
      int ed = it2 - a.begin();
      ed = min(ed, i - 1);
      if (ed - it1 + 1 >= 0) {
        ans += ed - it1 + 1;
      }
    }
    cout << ans << '\n';
  }
}


