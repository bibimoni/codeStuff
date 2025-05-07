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
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
    }
    int cnt1s = 0, ans = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i < k; i++) {
      cnt1s += a[i];
      ans += max(a[i] - 1, 0ll);
    }
    cout << ans + cnt1s << '\n';
  }
}


