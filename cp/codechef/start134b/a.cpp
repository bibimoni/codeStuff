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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    bool can = false;
    for(int i = 1; i < s.size(); i++) {
      if(!can && s[i] == s[i - 1]) {
        can = true;
      }
      else if(can) {
        can = false;
      }
      ans -= (int) can;
    }
    cout << ans << '\n';
  }
}

