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
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (i + 1 < s.size() && s[i] == s[i + 1] && s[i] == '0') {
      ans += 1;
      i += 1;
    } else {
      ans += 1;
    }
  }
  cout << ans << '\n';
}


