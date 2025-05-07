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
  vector<int> a(101);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int t, v;
    cin >> t >> v;
    mx = max(t, mx);
    a[t] += v;
  }
  int ans = 0;
  for (int i = 1; i <= mx; i++) {
    if (ans > 0) {
      ans -= 1;
    }
    ans += a[i];
  }
  cout << ans << '\n';
}


