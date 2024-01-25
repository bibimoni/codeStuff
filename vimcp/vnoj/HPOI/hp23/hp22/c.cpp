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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, x; cin >> n >> x;
  int p[n + 1], t[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> p[i] >> t[i];
  }
  int l = 1, r = (int) 1e18, ans = (int) 1e18;
  while(l <= r) {
    int mid = (l + r) >> 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      if(mid - t[i] >= 0) {
        cnt += ((mid - p[i]) / t[i]) + 1;
      }
    }
    if(cnt >= x) {
      r = mid - 1;
      ans = min(ans, mid);
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}


