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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    map<int, int> pre;
    for (int i = 1; i <= n; i++) {
      pre[a[i] + 1] += 1;
      pre[b[i] + 1] -= 1;
      pre[b[i]] += 0;
      pre[a[i]] += 0;
    }
    sort(a.begin() + 1, a.end());
    int cur = 0;
    int ans = 0;
    for (auto [p, v] : pre) {
      cur += v;
      if (cur <= k) {
        int lo = 1, hi = n, ret = n + 1;
        while (lo <= hi) {
          int mid = (lo + hi) >> 1;
          if (p <= a[mid]) {
            ret = mid;
            hi = mid - 1;
          } else {
            lo = mid + 1;
          }
        }
        int cnt = (n - ret + 1 > 0 ? n - ret + 1 : 0);
        ans = max(ans, (cnt + cur) * p);
      }
    }
    cout << ans << '\n';
  }
}


