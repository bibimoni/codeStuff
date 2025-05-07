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
    vector<pair<int, int>> p(n);
    vector<int> mark(n + 2, 0);
    for (int i = 0; i < n; i++) {
      cin >> p[i].first >> p[i].second;
      mark[p[i].first] |= (1 << p[i].second);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      if (mark[i] == 3) {
        ans += n - 2;
      } 
      if (i > 0 && (mark[i] & 1)) {
        ans += ((mark[i - 1] & 2) > 0) && ((mark[i + 1] & 2) > 0);
      }
      if (i > 0 && (mark[i] & 2)) {
        ans += ((mark[i - 1] & 1) > 0) && ((mark[i + 1] & 1) > 0);
      }
    }
    cout << ans << '\n';
  }
}


