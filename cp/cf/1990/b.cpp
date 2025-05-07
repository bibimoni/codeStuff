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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n);
    for (int i = y - 1; i < x; i++) {
      ans[i] = 1;
    }
    int cur = 1;
    for (int i = x; i < n; i++) {
      cur = (cur == -1 ? 1 : -1);
      ans[i] = cur;
    }
    cur = 1;
    for (int i = y - 2; i >= 0; i--) {
      cur = (cur == -1 ? 1 : -1);
      ans[i] = cur;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
}


