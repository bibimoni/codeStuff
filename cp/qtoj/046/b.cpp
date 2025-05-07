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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, x, y; cin >> a >> x >> y;
    if(y <= 0) {
      cout << x << '\n';
    }
    else if(y & 1) {
      cout << a - x << '\n';
    }
    else {
      cout << x << '\n';
    }
  }
}

