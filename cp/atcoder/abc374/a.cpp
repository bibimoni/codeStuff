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
  cout << (s.size() >= 3 && s[s.size() - 1] == 'n' && 
    s[s.size() - 2] == 'a' && s[s.size() - 3] == 's' ? "Yes\n" : "No\n");
}


