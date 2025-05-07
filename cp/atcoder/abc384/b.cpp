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
  int n, r;
  cin >> n >> r;
  for (int i = 0; i < n; i++) {
    int d, a;
    cin >> d >> a;
    if (d == 1) {
      if (1600 <= r && r < 2800) {
        r += a;
      }
    } else if (d == 2) {
      if (1200 <= r && r < 2400) {
        r += a;
      }
    }
  }
  cout << r << '\n';
}


