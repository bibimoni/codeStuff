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
    int a, b;
    cin >> a >> b;
    bool ok = false;
    if(a % 2 == 0) {
      int ta = a / 2, tb = b * 2;
      if(ta != b && tb != a) {
        cout << "YES\n";
        ok = true;
      }
    }
    if(b % 2 == 0 && !ok) {
      int tb = b / 2, ta = a * 2;
      if(ta != b && tb != a) {
        cout << "YES\n";
        ok = true;
      }
    }
    if(!ok) {
      cout << "NO\n";
    }
  }
}


