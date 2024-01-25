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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    bool check = false;
    for(int y = 1; y <= n; y++) {
      if(check) break;
      for(int x = 1; x <= n; x++) {
      int ta = 0, tb = 0, a = 0, b = 0; bool ok = true;
      int cntSet = 0;
      for(int i = 1; i <= n; i++) {
        ta += s[i] == 'A';
        tb += s[i] == 'B';
        if(i == n && ta != x && tb != x) {
          ok = false;
        }
        if(ta == x) a++, ta = 0, tb = 0, cntSet++;
        if(tb == x) b++, ta = 0, tb = 0, cntSet++;;
        if((a == y || b == y) && i != n) {
            ok = false;
          }
      }
      if(ok) {
        if(a > b && a == y) {
          cout << "A\n";
          check = true;
          break;
        }
        if(b > a && b == y) {
          cout << "B\n";
          check = true;
          break;
        }
      }
    } 
    }
    if(!check) cout << "?\n";
  }
}


