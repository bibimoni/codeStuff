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
  auto is = [&] (int x) -> bool {
    if (x <= 1) {
      return false;
    }
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  };

  int tt;
  cin >> tt;
  auto pow8 = [&] (int x) -> int {
    int ret = 1;
    for (int i = 0; i < 8; i++) {
      ret *= x;
    }
    return ret;
  };
  while (tt--) {
    int x;
    cin >> x;
    int sx = sqrt(x);
    bool ok = false;
    for (int i = 2; i <= min(sx, int(100)); i++) {
      if (is(i) && pow8(i) == x) {
        ok = true;
      }
    }
    if (sx * sx != x || ok) {
      cout << (ok ? "YES\n" : "NO\n");
    } else {
      int ssx = sqrt(sx);
      for (int i = 2; i <= ssx; i++) {
        if (is(i) && sx % i == 0 && i * i != sx && is(sx / i)) {
          ok = true;
        }
      }
      cout << (ok ? "YES\n" : "NO\n");      
    }
  }
}

