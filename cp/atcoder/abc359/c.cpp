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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  if (tx < sx) {
    swap(tx, sx);
    swap(ty, sy);
  }
  sx = (sx + sy) % 2 == 0 ? sx + 1 : sx;
  tx = (tx + ty) % 2 == 0 ? ty + 1 : ty;
  
}


