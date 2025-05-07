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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cur = 0, ans = 0;
    for (string s : a) {
      if (cur + s.size() <= m) {
        ans += 1;
        cur += s.size();
      } else {
        break;
      }
    }
    cout << ans << '\n';
  }
}


