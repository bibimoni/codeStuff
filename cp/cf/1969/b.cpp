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
    int n = s.size();
    int ans = 0, cnt1 = 0;
    for(int i = 0; i < n; i++) {
      cnt1 += (s[i] == '1');
      if(s[i] == '0') {
        ans += (cnt1 + 1) * (cnt1 > 1);
      }
    }
    cout << ans << '\n';
  }
}


