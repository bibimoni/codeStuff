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
    vector<int> m(n);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x -= 1;
      if (i == 0) {
        m[x] = 1;
      } else {
        bool cur = false;
        if (x > 0) {
          cur |= m[x - 1];
        } 
        if (x < n - 1) {
          cur |= m[x + 1];
        }
        ok &= cur;
        m[x] = 1;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


