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
    int n;
    cin >> n;
    int prev;
    cin >> prev;
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      int x;
      cin >> x;
      ok &= abs(x - prev) == 5 || abs(x - prev) == 7;
      prev = x;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


