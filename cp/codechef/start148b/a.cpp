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
    int n, x, y;
    cin >> n >> x >> y;
    int xa = 0, ya = 0;
    string s;
    cin >> s;
    int steps = 0;
    bool ok = false;
    for (char c : s) {
      steps += 1;
      if (c == 'R') {
        xa += 1;
      } else if (c == 'L') {
        xa -= 1;
      } else if (c == 'U') {
        ya += 1;
      } else {
        ya -= 1;
      }
      if (abs(x - xa) + abs(y - ya) == steps) {
        ok = true;
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}


