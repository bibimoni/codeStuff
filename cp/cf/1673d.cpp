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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int b, q, y;
    cin >> b >> q >> y;
    int c, r, z;
    cin >> c >> r >> z;
    bool check = (r % q == 0 && r >= q);
    if (!check) {
      cout << "0\n";
      continue;
    }
    
  }
}

