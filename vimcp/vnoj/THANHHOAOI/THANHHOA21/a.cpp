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
  // freopen("BAI1.INP", "r", stdin);
  // freopen("BAI1.OUT", "w", stdout);
  int n, a, b;
  //7 5 3
  cin >> n >> a >> b;
  cout << min(n - a, n - b) << ' ' << a;
}


