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
    int n, m; cin >> n >> m;
    bool ok = true;
    vector<bool> check(m, false);
    for(int i = 0; i < n; i++) {
      bool all = true, cant = true;
      for(int j = 0, x; j < m; j++) {
        cin >> x;
        if(!x) all = false;  
        if(x) cant = false, check[j] = true;
      }
      if(all || cant) ok = false;
    }
    for(int i = 0; i < m; i++) if(!check[i]) ok = false;
    cout << (ok ? "YES\n" : "NO\n");
  }
}

