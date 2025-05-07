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
    int b = x;
    int carry = 0;
    bool ok = true;
    int t1 = 0, t2 = 0;
    int cnt = 0;
    while(x) {
      int d = x % 10;
      d -= carry;
      bool f = false;
      if(t1 + t2 == b)
        break;
      for(int j = 5; j <= 9; j++) {
        if(f)
          break;
        for(int k = 5; k <= 9; k++) {
          if(j + k == 10 + d) {
            f = true;
            t1 = j * pow(10, cnt) + t1;
            t2 = k * pow(10, cnt) + t2;
            break;
          }
        }
      }
      if(!f) { 
        ok = false;
        break;
      }
      cnt++;
      carry = 1;
      x /= 10;
    }
    cout << (ok && t1 + t2 == b ? "YES\n" : "NO\n");
  }
}


