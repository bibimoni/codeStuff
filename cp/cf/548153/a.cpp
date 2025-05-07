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
    int n, a, b;
    cin >> n >> a >> b;
    int mnx = n, mxx = 1, mny = n, mxy = 1;
    for (int i = 0; i < 3; i++) {
      int x, y;
      cin >> x >> y;
      mnx = min(mnx, x);
      mny = min(mny, y);
      mxx = max(mxx, x);
      mxy = max(mxy, y);
    }
    cout << (mnx < a && a < mxx && mny < b && b < mxy ? "NO\n" : "YES\n");
  }
}

