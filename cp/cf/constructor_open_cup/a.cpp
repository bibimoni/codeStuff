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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int curr = k;
    if(l <= curr && curr <= r) {
      cout << "0\n";
      continue;
    }
    else if(r < curr) {
      curr -= a[0];
    }
    else if(curr < l)  {
      curr += a[0];
    }
    bool ok = false;
    for(int i = 0; i < n; i++) {
      dbg(curr);
      if(l <= curr && curr <= r) {
        cout << a[i] << '\n';
        ok = true;
        break;
      }
      if(i == n - 1) {
        break;
      }
      else if(r < curr) {
        curr -= (a[i + 1] - a[i]);
      }
      else if(curr < l) {
        curr += (a[i + 1] - a[i]);
      }  
    }
    if(!ok) {
      cout << "-1\n";
    }
  }
}


