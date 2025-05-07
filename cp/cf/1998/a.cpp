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
    int x, y, k;
    cin >> x >> y >> k;
    if (k % 2) {
      cout << x << ' ' << y << '\n';
    }
    for (int i = 0; i < k - (k % 2); i += 2) {
      cout << x + (i + 1) << ' ' << y << '\n';
      cout << x - (i + 1) << ' ' << y << '\n';
    }
  } 
}


