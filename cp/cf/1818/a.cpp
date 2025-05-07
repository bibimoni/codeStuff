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
    int n, k;
    cin >> n >> k;
    string pre;
    cin >> pre;
    int ans = 1;
    for(int i = 0; i < n - 1; i++) {
      string t;
      cin >> t;
      ans += (t == pre);
    }
    cout << ans << '\n';
  }
}



