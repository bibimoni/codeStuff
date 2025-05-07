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
    vector<int> b(n);
    multiset<int> a;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int id = 0;
      bool ok = false;
      for(int x : a) {
        if(x > b[id]) {
          ans++;
          ok = true;
          a.erase(prev(a.end()));
          break;
        }
        id++;
      }
      if(!ok)
        break;
      a.insert(1);
    }
    cout << ans << '\n';
  }
}


