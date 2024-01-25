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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int maxX = 0, minX = INF, maxY = 0, minY = INF;
    for(int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      maxX = max(maxX, x);
      minX = min(minX, x);
      maxY = max(maxY, y);
      minY = min(minY, y);
    }
    if(minX < 0 && maxX > 0 && minY < 0 && maxY > 0) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
}


