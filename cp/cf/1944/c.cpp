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
    vector<int> pos(n, 0);
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pos[x]++;
    }
    int ans = 0, flag = false;;
    for(int i = 0; i < n; i++) {
      if(!pos[i]) {
        break;
      }
      if(flag && pos[i] == 1)
        break;
      if(pos[i] == 1)
        flag = true;
      ans++;
    }
    cout << ans << '\n';
  }
}


