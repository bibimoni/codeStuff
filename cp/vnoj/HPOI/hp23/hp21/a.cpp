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
  string ans = "";
  string s; getline(cin, s);
  for(char i : s) {
    if(i >= 'a' && i <= 'z') ans += i;
    else if(i >= 'A' && i <= 'Z') ans += i;
  }
  cout << ans;
}


