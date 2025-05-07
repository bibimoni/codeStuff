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
  int x;
  cin >> x;
  int cnt = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cnt += (i * j != x ? (i * j) : 0);
    }
  }
  cout << cnt;
}


