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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<int>());
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    while (q--) {
      int x;
      cin >> x;
      int lo = 1, hi = n, ans = -1;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (pre[mid] >= x) {
          ans = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      cout << ans << '\n';
    }
  }
}

