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
  freopen("CAU1.INP", "r", stdin);
  freopen("CAU1.OUT", "w", stdout);
  int a, b; cin >> a >> b;
  int ans = 0, t = __gcd(a, b);
  for(int i = 1; i * i <= t; i++) {
    if(t % i == 0) {
      ans++;
      if(t / i != i) {
        ans++;
      }
    }
  }
  cout << ans;
}


