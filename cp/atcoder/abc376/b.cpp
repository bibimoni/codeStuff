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
  int n, q;
  cin >> n >> q;
  int rhs = 2, lhs = 1;
  int ans = 0;
  auto add = [&] (int t, int del) -> int {
    t += del;
    if (t == n + 1) {
      return 1;
    } 
    if (t == 0) {
      return n;
    }
    return t;
  };
  while (q--) {
    char h;
    int t;
    cin >> h >> t;
    dbg(lhs, rhs);
    if (h == 'R') {
      int tmp = rhs;
      int del = 0;
      bool ok = true;
      while (t != tmp) {
        if (tmp == lhs) {
          ok = false;
          break;
        }
        tmp = add(tmp, 1);
        del += 1;
      }
      if (ok) {
        dbg(del);
        ans += del;
        rhs = t;
        continue;
      }
      tmp = rhs;
      del = 0;
      while (t != tmp) {
        tmp = add(tmp, -1);
        del += 1;
      }
      ans += del;
      rhs = t;
      dbg(del);
    } else {
      int tmp = lhs;
      int del = 0;
      bool ok = true;
      while (t != tmp) {
        if (tmp == rhs) {
          ok = false;
          break;
        }
        tmp = add(tmp, 1);
        del += 1;
      }
      if (ok) {
        dbg(del);
        ans += del;
        lhs = t;
        continue;
      }
      tmp = lhs;
      del = 0;
      while (t != tmp) {
        tmp = add(tmp, -1);
        del += 1;
      }
      ans += del;
      lhs = t;
      dbg(del);
    }
  }
  cout << ans << '\n';
}


