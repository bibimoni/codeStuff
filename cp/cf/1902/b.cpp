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

#define int            long long
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, p, l1, t;
    cin >> n >> p >> l1 >> t;
    int l = 1, r = n, ans = n;
    while(l <= r) {
      int mid = (l + r) / 2;
      int extraPts = min(mid * 2 * t, ((n / 7) + (n % 7 != 0)) * t);
      int pts = l1 * mid + extraPts;
      dbg(pts, mid, ans);
      if(pts >= p) {
        r = mid - 1;
        ans = mid;
      }
      else {
        l = mid + 1;
      }
    } 
    cout << n - ans << '\n';
  }
}


