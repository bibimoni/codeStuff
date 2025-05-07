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
    int n;
    cin >> n;
    bool ok = false;
    string ans = "";
    for(char j = 'a'; j <= 'z'; j++) {
      if(ok)
        break;
      for(char i = 'a'; i <= 'z'; i++) {
        if(ok) 
          break;
        for(char z = 'a'; z <= 'z'; z++) {
          if(j + i + z -'a' - 'a' - 'a' + 3 == n) {
            cout << j << i << z << '\n';
            ok = true;
            break;
          } 
        }
      }
    }
  }
}


