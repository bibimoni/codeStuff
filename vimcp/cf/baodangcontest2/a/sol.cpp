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
    int x, y; cin >> x >> y;
    if(x == 0 && y == 0) cout << "0\n";
    else if((int) sqrt(x * x + y * y) == sqrt(x * x + y * y)) cout << "1\n";
    else cout << "2\n";
  }
}

