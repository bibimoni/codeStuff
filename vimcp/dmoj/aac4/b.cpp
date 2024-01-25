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

int __lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q; cin >> n >> q;
  int boundary = 0;
  int a[n + 1], prefLcm[n + 1]; 
  prefLcm[0] = 1; 
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }  
  for(int i = 1; i <= n; i++) {
    boundary++;
    int curr = __lcm(prefLcm[i - 1], a[i]);
    prefLcm[i] = curr;
    if(curr > (int) 1e9) break;
  }
  while(q--) {
    int t; cin >> t;
    int l = 1, r = boundary, ans = -1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(t % prefLcm[mid] == 0) {
        l = mid + 1;
      }  
      else {
        r = mid - 1;
        ans = mid;
      }
    }
    dbg(ans, boundary);
    cout << ans << '\n';
  }
}


