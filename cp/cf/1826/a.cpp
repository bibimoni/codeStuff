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
    int l[n];
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      l[i] = x;
    }
    int lair = -1;
    for(int i = 0; i <= n; i++) {
      int cnt = 0;
      for(int la : l) {
        if(la > i) {
          cnt++;
        }
      }
      if(cnt == i) {
        lair = i;
      }
    }    
    cout << lair << '\n';
  }
}


