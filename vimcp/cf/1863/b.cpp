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
    int n; cin >> n;
    int p[n], pos[n + 1];
    for(int i = 0; i < n; i++) {
      cin >> p[i];
      pos[p[i]] = i;
    }
    int cnt = 0;
    for(int i = 1; i < n; i++) {
      if(pos[i] > pos[i + 1]) cnt++;
    }
    cout << cnt << '\n';
  }
}


