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
  int d, n;
  cin >> n >> d;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for (char &c : s) {
    if (d > 0 && c == '@') {
      c = '.';
      d -= 1;
    } 
  }
  reverse(s.begin(), s.end());
  cout << s << '\n';
}


