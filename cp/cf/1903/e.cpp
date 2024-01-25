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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int x, y; cin >> x >> y;
    vector<pair<int, int>> pts(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> pts[i].first >> pts[i].second;
    }
    
  }
}


