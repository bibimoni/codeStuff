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
  int h;
  cin >> h;
  int curr = 0, ans = 0;
  for(int i = 0; i < 30; i++) {
    curr += (1 << i);
    if(curr > h) {
      ans = i + 1;
      break;
    }
  }
  cout << ans;
}


