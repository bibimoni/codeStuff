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

const int INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = INF;
    for(int one = 0; one < 5; one++) 
      for(int three = 0; three < 5; three++) 
        for(int six = 0; six < 5; six++)
          for(int ten = 0; ten < 5; ten++) {
            int curr = one * 1 + six * 6 + three * 3 + ten * 10;
            if(curr > n) 
              continue;
            if(n >= curr && (n - curr) % 15 == 0) {
              ans = min(ans, one + three + six + ten + (n - curr) / 15);
            }
          }
    cout << ans << '\n';
  }
}


