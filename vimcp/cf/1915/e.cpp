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
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    set<int> diff; diff.insert(0ll);
    bool ok = false; int odd = 0, even = 0;
    for(int i = 1; i <= n; i++) {
      if(i & 1) odd += a[i];
      else even += a[i];
      int curr = odd - even;
      if(diff.find(curr) != diff.end()) {
        ok = true;
        break;
      }
      diff.insert(curr);
    }
    cout << (ok ? "YES\n" : "NO\n");

  }
}


