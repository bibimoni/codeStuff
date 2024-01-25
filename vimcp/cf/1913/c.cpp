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
  int m; cin >> m;
  vector<int> pwr(32, 0);
  while(m--) {
    int type; cin >> type;
    if(type == 1) {
      int x; cin >> x;
      pwr[x]++;
      for(int j = 0; j < 32; j++) { 
        if(pwr[j] == 1) continue;
        int k = 0, curr = pwr[j] * (1ll << j);
        pwr[j] = 0;
        while(k < 32) {
          if(curr & (1ll << k)) pwr[k]++;
          k++;
        }
      }
    }   
    else if(type == 2) {
      int w; cin >> w;
      if(w == 0) {
        cout << "YES\n";
        continue;
      }
      for(int j = 0; j < 32; j++) {
        if(!pwr[j]) continue;
        if(w & (1ll << j)) w -= (1ll << j);
        if(w == 0) break;
      }
      if(w != 0) {
        cout << "NO\n";
      }
      else {
        cout << "YES\n";
      }
    }
  }
}


