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
  int m; cin >> m;
  vector<int> pwr(32, 0);
  while(m--) {
    int type; cin >> type;
    if(type == 1) {
      int x; cin >> x;
      pwr[x]++;
    }
    if(type == 2) {
      int w; cin >> w;
      for(int j = 31; j >= 0; j--) {
        if(!pwr[j]) continue;
        for(int i = 1; i <= pwr[j]; i++) {
          if(w >= (1ll << j)) {
            w -= (1ll << j);
          }
        }
      }
      if(w == 0) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
}

