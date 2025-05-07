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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  while (q--) {
    int b, k;
    cin >> b >> k;
    int l = 0, r = int(2e8), ret = 0;
    while (l <= r) {
      int m = (l + r) >> 1;
      int cnt = upper_bound(a.begin() + 1, a.end(), b + m) - lower_bound(a.begin() + 1, a.end(), b - m);
      if (cnt >= k) {
        ret = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << ret << '\n';
  }
}


