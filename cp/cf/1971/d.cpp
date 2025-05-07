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
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int ans = 1;
    for(int i = 1; i < s.size(); i++) {
      if(s[i - 1] != s[i])
        ans++;
    }
    for(int i = 1; i < s.size(); i++) {
      if(s[i - 1] == '0' && s[i] == '1') {
        ans--;
        break;
      }
    }
    cout << ans << '\n';
  }
}


