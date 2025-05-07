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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int maxA = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      maxA = max(a[i], maxA);
    }
    int l = 0, r = maxA, ret = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      int curr = 0;
      for(int i = 1; i <= n; i++) {
        if(mid >= a[i])    
          curr += mid - a[i];
      }
      if(curr <= k) {
        ret = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    int rem = k;
    for(int i = 1; i <= n; i++) {
      if(a[i] <= ret) {
        rem -= ret - a[i];
      }
    }
    int ans = ret * n - n + 1 + rem;
    for(int i = 1; i <= n; i++) {
      if(a[i] > ret) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}


