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
    int n, k; cin >> n >> k;
    for(int i = 1; i <= k; i++) {
      cout << i << ' ';
    }
    for(int i = n; i >= k + 1; i--) {
      cout << i << ' ';
    }
    cout << '\n';
   }
}

