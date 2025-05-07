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
    vector<int> p(3);
    cin >> p[0] >> p[1] >> p[2];
    sort(p.begin(), p.end());
    int ans = 0;
    bool can = true;
    while((p[0] != 0) || (p[1] != 0) || (p[2] != 0)) {
      if(p[1] > 0) {
        p[1]--;
        p[2]--;
        ans++;
      }
      else if(p[0] > 0) {
        p[0]--;
        p[1]--;
        ans++;
      }
      else {
        can &= (p[0] % 2 == 0) && (p[1] % 2 == 0) && (p[2] % 2 == 0);
        break;
      }
      sort(p.begin(), p.end());
    } 
    cout << (!can ? -1 : ans) << '\n';
  }
}


