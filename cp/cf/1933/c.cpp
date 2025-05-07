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
    int a, b, l;
    cin >> a >> b >> l;
    int ans = 0;
    int at = 1, bt = 1;
    map<int, int> f;
    for(int xa = 1; at <= l; xa++) {
      bt = 1;
      for(int xb = 1; bt <= l; xb++) {
        if(l % (at * bt) == 0) {
          if(!f[l / (at * bt)])
            ans++;
          f[l / (at * bt)] = true;
        }
        bt *= b;
      }
      at *= a;  
    }
    cout << ans << '\n';
  }
}


