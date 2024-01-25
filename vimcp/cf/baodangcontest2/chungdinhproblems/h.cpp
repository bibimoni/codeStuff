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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int p, q; 
    cin >> p >> q;
    auto solve = [&] () {
      for(int x2 = 0; x2 <= 20; x2++) {
        for(int x3 = 0; x3 <= 20; x3++) {
          for(int y2 = 0; y2 <= 20; y2++) {
            for(int y3 = 0; y3 <= 20; y3++) {
              if(x2 + x3 + y2 + y3 > 20 || x2 + x3 + y2 + y3 == 0) {
                continue;
              }
              if(x2 + x3 == 0 || y2 + y3 == 0) {
                continue;
              }
              int x = pow(2ll, x2) * pow(3ll, x3);
              int y = pow(2ll, y2) * pow(3ll, y3);
              int top = x - y;
              if(top == 0) {
                continue;
              }
              int bot = pow(2ll, x2 + y2) * pow(3ll, x3 + y3);
              int gcd = __gcd(top, bot);
              top /= gcd;
              bot /= gcd;
              if(p == top && bot == q) {
                return true;
              }
            }
          }
        }
      }
      return false;
    };
    if(solve()) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}

