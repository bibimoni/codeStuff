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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sz = n / 2;
  cout << ((n % 2 != 0 && s.substr(0, sz) == string(sz, '1') && s[sz] == '/' && s.substr(sz + 1) == string(sz, '2') ? "Yes\n" : "No\n"));
}


