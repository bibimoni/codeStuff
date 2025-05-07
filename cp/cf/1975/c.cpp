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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = *min_element(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
      if(i > 0 && a[i] <= a[i - 1]) 
        ans = max(ans, a[i]);
      if(i < n - 1 && a[i] <= a[i + 1])
        ans = max(ans, a[i]);
      if(i > 1) {
        vector<int> d = {a[i - 2], a[i - 1], a[i]};
        sort(d.begin(), d.end())
        ans = max(ans, d[1]);
      }
    }
    cout << ans << '\n';
  }
}


