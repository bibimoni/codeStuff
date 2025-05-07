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
  set<string> st;
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    for(int j = 0; j <= i; j++) {
      st.insert(s.substr(j, i - j + 1));
    }
  }
  cout << (int) st.size();
}


