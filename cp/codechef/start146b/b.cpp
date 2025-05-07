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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != 0) {
        continue;
      }
      int pl = pre[i - 1];
      int pr = pre[n] - pre[i];
      if (abs(pl - pr) > 1) {
        continue;
      }
      ans += 1 + (abs(pl - pr) == 0);
    }
    cout << ans << '\n';
  }
} 


