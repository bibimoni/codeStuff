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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans = m;
    for (int i = 0; i < m; i++) {
      int prev = i;
      for (int j = 0; j < n && prev < m; j++) {
        if (a[j] == b[prev]) {
          prev++;
        }
      }
      ans = min(ans, i - prev + m);
    }
    cout << ans + n << '\n';
  }
}


