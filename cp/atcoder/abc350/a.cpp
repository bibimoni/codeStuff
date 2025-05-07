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
  string s;
  cin >> s;
  int num = (s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0');
  cout << (s.substr(0, 3) == "ABC" && (num >= 1 && num <= 349 && num != 316) ? "Yes\n" : "No\n");
}


