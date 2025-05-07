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
    int x, m;
    cin >> x >> m;
    set<int> ans;
    for (int y = 1; y <= m; y++) {
      int k = x ^ y;
      if (x % k == 0 || y % k == 0) {
        ans.insert(y);
      }
    } 
    // dbg(ans);
    cout << ans.size() << '\n';
  }
}

