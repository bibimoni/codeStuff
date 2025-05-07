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
    string a, b;
    cin >> a >> b;
    int n = a.size();
    bool ok = false;
    for(int i = 0; i < n; i++) {
      if(a[i] == b[i])
        continue;
      if(!ok) {
        if(a[i] < b[i])
          swap(a[i], b[i]);
        ok = true;
      }
      else if(ok && a[i] > b[i]) {
        swap(a[i], b[i]);
      }
    }
    cout << a << '\n' << b << '\n';
  }
}


