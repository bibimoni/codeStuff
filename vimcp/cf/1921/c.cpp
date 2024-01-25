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
    int n, f, a, b; cin >> n >> f >> a >> b;
    int m[n];
    for(int i = 0; i < n; i++) {
      cin >> m[i];
    }
    int prev = 0; bool ok = true;
    for(int i = 0; i < n; i++) {
      int consume = min((m[i] - prev) * a, b);
      if(f - consume <= 0) {
        ok = false;
        break;
      }
      else {
        f -= consume;
      }
      prev = m[i];
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


