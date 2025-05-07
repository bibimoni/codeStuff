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
    int l, r;
    cin >> l >> r;
    int ans = 0, curr = 1;
    while(curr * 2 <= r) {
      curr *= 2;
      ans++;
    }
    cout << ans << '\n';
  }
}


