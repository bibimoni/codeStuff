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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int a, b, c; cin >> a >> b >> c;
    if(c > 0) {
      cout << "CURVE UP" << endl;
    }
    else if(c < 0) {
      cout << "CURVE DOWN" << endl;
    }
    else {
      cout << "NO CURVE" << endl;
    }
  }
}



