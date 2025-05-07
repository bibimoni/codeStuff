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
  int r, b, g;
  cin >> r >> g >> b;
  int ans = r + b + g;
  string t;
  cin >> t;
  if (t == "Blue") {
    cout << min(r, g);
  } else if (t == "Green") {
    cout << min(b, r);
  } else {
    cout << min(g, b);
  }
}


