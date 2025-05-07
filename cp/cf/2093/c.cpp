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
    int x, k;
    cin >> x >> k;
    if (x == 1 && k == 2) {
      cout << "YES\n";
      continue;
    }
    bool isPrime = x >= 2;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        isPrime &= false;
        break;
      }
    }
    cout << (isPrime && k == 1 ? "YES\n" : "NO\n");
  }
}


