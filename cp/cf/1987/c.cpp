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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> h[i];
    }
    int ans = h[n];
    for (int i = n - 1; i >= 1; i--) {
      ans = max(ans + 1, h[i]);
    }
    cout << ans << '\n';
  }
}


