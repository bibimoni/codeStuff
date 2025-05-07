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
    int n, x;
    cin >> n >> x;
    int last = -1;
    for (int j = 0; j < 30; j++) {
      if ((x >> j) & 1) {
        n -= 1;
        last = j;
      } 
    }
    if (n < 0) {
      cout << ((x == 0 && n == 1) ? -1 : x) << '\n';
    } else if (n == 0) {
      cout << x << "\n";
    } else {
      if (n % 2 == 0) {
        cout << x + n << '\n';
      } else {
        if (x != -1) {
          cout << x + 2 * (int(1) << (last == 0 ? 1 : 0)) + (n - 1) << '\n';
        } else if (n < 3) {
          cout << "-1\n";
        } else {
          cout << 3 + n << '\n';
        }
      }
    }
  }
}


