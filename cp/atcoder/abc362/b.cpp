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
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  auto d = [&] (int x, int y, int x2, int y2) -> int {
    return (x - x2) * (x - x2) + (y - y2) * (y - y2);
  };
  vector<int> e = {d(xa, ya, xb, yb), d(xa, ya, xc, yc), d(xb, yb, xc, yc)};
  sort(e.begin(), e.end());
  cout << (e[0] + e[1] == e[2] ? "Yes\n" : "No\n");
} 


