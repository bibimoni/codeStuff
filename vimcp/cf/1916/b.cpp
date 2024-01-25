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
    int a, b; cin >> a >> b;
    int lcm = 1ll * a * b / __gcd(a, b);
    if(lcm == max(a, b)) cout << lcm * (max(a, b) / min(a, b));
    else cout << lcm;
    cout << '\n';
  }
}


