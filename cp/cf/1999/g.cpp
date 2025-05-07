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
    auto ask = [&] (int a, int b) -> int {
      cout << "? " << a << ' ' << b << '\n';
      cout.flush();
      int ans;
      cin >> ans;
      return ans;
    };
    const int X = 999;
    int l = 1, r = X, ret = X;
    while (l <= r) {
      int m1 = (2 * l + r) / 3;
      int m2 = (2 * r + l) / 3;
      int g = ask(m1, m2);
      if (g == (m2 + 1) * m1) {
        l = m1 + 1;
        r = m2 - 1;
        ret = min(ret, m2);
      } else if (g == (m1 + 1) * (m2 + 1)) {
        ret = min(ret, m1);
        r = m1 - 1;
      } else if (g == m1 * m2) {
        l = m2 + 1;
      }
    }    
    cout << "! " << ret << '\n';
    cout.flush();
  }
}


