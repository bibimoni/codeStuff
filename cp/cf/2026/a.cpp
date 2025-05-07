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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, k;
    cin >> x >> y >> k;
    int mn = min(x, y);
    cout << "0 0 " << mn << ' ' << mn<< '\n';
    cout << "0 " << mn << " " << mn << " 0\n";
  }
}


