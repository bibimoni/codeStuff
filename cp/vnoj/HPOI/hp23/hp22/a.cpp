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
  string s; cin >> s;
  string cmp = "virus";
  int ans = 0;
  for(int i = 0; i < s.size() - 4; i++) {
    if(s.substr(i, 5) == cmp) ans++;
  }
  cout << ans ;
}


