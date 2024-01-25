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
  int tt; cin >> tt;
  while(tt--) {
    int n, q; cin >> n >> q;
    for(int i = 1; i < n; i++) {
      cout << i << ' ' << i + 1 << '\n';
    }
    int curr = 2, dist = n - 1;
    while(q--) {
      int x; cin >> x;
      if(dist == x) {
        cout << "-1 -1 -1\n";
      }
      else {
        cout << "1 " << curr << ' ' << (n - x + 1) << '\n';
        curr = n - x + 1;
        dist = x;
      }
    }
  }
}


