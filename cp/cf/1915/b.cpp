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
    vector<string> a(3);
    for(int i = 0; i < 3; i++) {
      cin >> a[i];
      bool hasA = false, hasB = false, hasC = false;
      for(char t : a[i]) {
        if(t == 'A') hasA = true;
        if(t == 'B') hasB = true;
        if(t == 'C') hasC = true;
      }
      if(hasA && hasB && hasC) continue;
      if(!hasA) cout << 'A';
      if(!hasB) cout << 'B';
      if(!hasC) cout << 'C';
    }
    cout << '\n';

  }
}


