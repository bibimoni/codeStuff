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
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; i + j < n; j++) {
      int cur = 1;
      while (i + j * cur < n && h[i + j * cur] == h[i]) {
        cur += 1;
      }
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
}


