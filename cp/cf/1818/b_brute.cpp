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
  for(int n = 2; n <= 10; n++) {
    if((n * (n + 1) / 2) % n == 0) {
      continue;
    }
    cout << n << '\n';
  }
}



