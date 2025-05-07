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
    vector<int> b(n + 1);
    for(int i = 0; i <= n; i++) {
      cin >> b[i];
    }
    int ans = 1;
    int more = (int) 1e9;
    for(int i = 0; i < n; i++) {
      ans += abs(a[i] - b[i]);
      bool in = false;
      if((a[i] <= b[n] && b[n] <= b[i]) || (b[i] <= b[n] && b[n] <= a[i])) {
        in = true;
      }
      if (in) {
        more = 0;
      }
      more = min({more, abs(a[i] - b[n]), abs(b[i] - b[n])});
    }
    ans += more;
    cout << ans << '\n';
  }
}


