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
#define sz(_x) (_x).size()

const int MOD = (int) 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << n % MOD << '\n';
      continue;
    }
    int a = 1, b = 1, cnt = 1;
    while (a != 0) {
      int c = (a + b) % k;
      a = b;
      b = c;
      cnt += 1;
    }
    cout << (cnt % MOD) * (n % MOD) % MOD << '\n';
  }
}


