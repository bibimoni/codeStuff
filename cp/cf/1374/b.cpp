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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int cnt3 = 0;
    int tmp = n;
    while(tmp % 3 == 0)
      cnt3++,
      tmp /= 3;
    int cnt2 = 0;
    tmp = n;
    while(tmp % 2 == 0)
      cnt2++,
      tmp /= 2;
    if(cnt2 > cnt3) {
      cout << "-1\n";
    }
    else {
      int cnt = cnt2;
      while(cnt < cnt3) {
        n *= 2;
        cnt++;
      }
      while(n % 6 == 0) {
        n /= 6;
      }
      cout << (n == 1 ? (2 * cnt3 - cnt2) : -1) << '\n';
    }
  }
}


