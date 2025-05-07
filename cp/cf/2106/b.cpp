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
    for (int i = 0; i < n; i++) {
      if (i == x) {
        continue;
      }
      cout << i << " ";
    }
    if (x < n) {
      cout << x << '\n';
    } else {
      cout << '\n';
    }
  }
}


