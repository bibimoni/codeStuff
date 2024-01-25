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
    string t; cin >> t;
    bool ok = false;

    for(int i = 1; i < t.size(); i++) {
      if(t[i] == '0') continue;
      int num1 = 0, num2 = 0;
      for(int j = 0; j < i; j++) {
        num1 = num1 * 10 + (t[j] - '0');
      }
      for(int j = i; j < t.size(); j++) {
        num2 = num2 * 10 + (t[j] - '0');
      }
      if(num1 < num2 && num2 > 0 && num1 > 0) {
        cout << num1 << ' ' << num2 << '\n';
        ok = true;
        break;
      }
    }
    if(!ok) cout << "-1\n";
  }
}


