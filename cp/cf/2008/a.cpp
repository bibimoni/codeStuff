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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    if (b % 2 == 0) {
      cout << (a % 2 ? "NO\n" : "YES\n");
    } else {
      cout << (a % 2 == 0 && a >= 2 ? "YES\n" : "NO\n");
    }
  }
}


