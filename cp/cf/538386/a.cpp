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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x = 0, y = 0;
    bool ok = false;
    for (int k = 0; k < 10; k++) {
      for (char c : s) {
        if (c == 'N') {
          y += 1;
        } else if (c == 'S') {
          y -= 1;
        } else if (c == 'W') {
          x -= 1;
        } else {
          x += 1;
        }
        if (x == a && y == b) {
          ok |= true;
        }
      }
    } 
    cout << (ok ? "YES\n" : "NO\n");
  } 
}


