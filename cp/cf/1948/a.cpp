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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    if(n % 2 != 0) {
      cout << "NO\n";
    }
    else {
      bool turn = false;
      cout << "YES\n";
      for(int i = 0; i < n; i += 2) {
        if(turn)
          cout << "AA";
        else 
          cout << "BB";
        turn = !turn;
      }
      cout << '\n';
    }
  }
}


