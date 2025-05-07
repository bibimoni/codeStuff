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
  int y;
  cin >> y;
  if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
    cout << "365"
  } else {
    cout << "366";
  }
}


