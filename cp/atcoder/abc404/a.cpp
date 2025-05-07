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
  set<char> st(s.begin(), s.end());
  char ans = '#';
  for (char c = 'a'; c <= 'z'; c++) {
    if (st.find(c) == st.end()) {
      ans = c;
    }
  }
  cout << ans << '\n';
}


