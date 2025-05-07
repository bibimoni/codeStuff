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
    string s;
    cin >> s;
    string ans = (s[0] == 'a' ? 'b' : 'a') + s;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        ans = s.substr(0, i) + (s[i] == 'a' ? 'b' : 'a') + s.substr(i);
        break;
      }
    }
    cout << ans << '\n';
  }
}


