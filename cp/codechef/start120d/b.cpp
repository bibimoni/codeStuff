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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x;
    cin >> x;
    int curr = 1, total = 1;
    bool ok = true;
    for(int i = 2; i <= 7; i++) {
      if(total + curr * 2 > x) {
        ok = false;
        break;
      }
      curr *= 2;
      total += curr;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


