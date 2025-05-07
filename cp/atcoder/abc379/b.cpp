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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'O') {
      cnt += 1;
    } else {
      cnt = 0;
    }
    if (cnt == k) {
      ans += cnt == k;
      cnt = 0;
    }
  }
  cout << ans << '\n';
} 


