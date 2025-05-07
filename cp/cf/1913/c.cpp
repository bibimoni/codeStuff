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
  int m;
  cin >> m;
  vector<int> pwr(32, 0);
  while (m--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      pwr[x] += 1;
    } else {
      for (int j = 31; j >= 0; j--) {
        int b = x / (1ll << j);
        for (int i = min(pwr[j], b); i >= 1; i--) {
          if (x >= i * (1ll << j)) {
            x -= i * (1ll << j);
            break;
          }
        }
      }
      cout << (x == 0 ? "YES\n" : "NO\n");
    }
  }
}

