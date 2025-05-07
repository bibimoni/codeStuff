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
    int m, s; 
    cin >> m >> s;
    vector<bool> pos(105, 0);
    set<int> st;
    for(int i = 0; i < m; i++) {
      int x;
      cin >> x;
      pos[x] = true;
    }
    int currSum = 0;
    for(int i = 1; i <= 100; i++) {
      if(!pos[i] && currSum + i > s) {
        break;
      }
      if(!pos[i]) {
        currSum += i;
      }
      else {
        pos[i] = false;
      }
    }
    bool ok = true;
    for(int i = 1; i <= 100; i++) {
      if(pos[i]) {
        ok = false;
        break;
      }
    }
    cout << (ok && currSum == s ? "YES\n" : "NO\n");
  }
}


