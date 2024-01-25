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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int cntS = 0, cntT = 0; int move = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == t[i] && s[i] == '1') continue;
      if(s[i] != t[i]) ans++;
      cntS += s[i] == '1';
      cntT += t[i] == '1';
    }
    cout << (ans + abs(cntS - cntT)) / 2 << '\n';

  }
}


