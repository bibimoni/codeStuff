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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int sum = accumulate(a.begin() + 1, a.end(), 0);
    int ans = n;
    for(int seg = 1; seg <= n; seg++) {
      if(sum % seg != 0)
        continue;
      int part = sum / seg, curr = 0, l = 1;
      bool ok = true;
      int tmp = 1;
      for(int r = 1; r <= n; r++) {
        if(curr + a[r] > part) {
          ok = false;
          break;
        }
        curr += a[r];
        if(curr == part) {  
          curr = 0;
          tmp = max(tmp, r - l + 1);
          l = r + 1;
        }
      }
      if(ok && curr == 0) {
        ans = min(ans, tmp);
      }
    }
    cout << ans << '\n';
  }
}


