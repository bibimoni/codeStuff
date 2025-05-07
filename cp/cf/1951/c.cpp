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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    //7 5
    sort(a.begin(), a.end());
    int ans = 0;
    if(k <= m) {
      ans = a[0] * k;
      cout << ans << '\n';
      continue;
    }
    for(int i = 0; i < n; i++) {
      if(k > m) {
        ans += (i * m + a[i]) * m;
        k -= m;
      }
      else {
        ans += (i * m + a[i]) * k;
        break;
      }
    }
    cout << ans << "\n";
  }
}


