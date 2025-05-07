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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i < n && k > 0; i += 2) {
      int need = min(a[i - 1] - a[i], k);
      k -= need;
      a[i] += need;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        ans -= a[i];
      } else {
        ans += a[i];
      }
    }
    cout << ans << '\n';
  }
}


