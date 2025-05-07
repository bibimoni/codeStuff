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
    sort(a.begin(), a.end());
    int ans = a[n - 1] - a[0];
    for (int t = 0; t <= a[0]; t++) {
      int curr = 0;
      for (int i = 0; i < n; i++) {
        int p = (t == 0 ? k : min(k, a[i] / t));
        curr = max(curr, a[i] / p - t);
      }
      ans = min(ans, curr);
    }
    cout << ans << '\n';
  }
}

