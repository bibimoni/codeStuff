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
    for(int i = 1; i <= n - 2; i++) {
      cout << i << ' ' << n - i + 1 << '\n';
    }
    cout << n << " 1\n";
    cout << n << " 2\n";
  }
}


