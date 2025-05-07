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
    if(k <= 4 * n - 4) {
      cout << (k - 1) / 2 + 1;
    }
    else if(k == 4 * n - 3) {
      cout << 2 * n - 1 << '\n';
    }
    else if(k == 4 * n - 2) {
      cout << 2 * n << '\n';
    }
  }
}


