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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    if(a + 1 != c) {
      cout << "-1\n";
      continue;
    }
    int t =  a ? (64 - __builtin_clzll(a)) : 0;
    int p = (1 << t) - a - 1;
    b -= min(b, p);
    cout << t + (b + c - 1) / c << '\n';
  }
}

