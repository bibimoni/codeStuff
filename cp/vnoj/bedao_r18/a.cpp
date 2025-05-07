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
    if((a < 0 && -a == b) || (b < 0 && -b == a)) {
      cout << "0 0\n";
      continue;
    }
    int ta = a / __gcd(abs(a), abs(b));
    int tb = b / __gcd(abs(a), abs(b));
    if(ta + tb < 0) {
      ta = -ta;
      tb = -tb;
    }
    cout << ta << ' ' << tb << '\n';
  }
}


