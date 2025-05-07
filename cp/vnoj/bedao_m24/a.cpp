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
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> st;
  for(char i : s) {
    st.insert(i);
  }
  string tmp = s;
  reverse(tmp.begin(), tmp.end());
  if(st.size() == 1) {
    cout << 0;
  }
  else {
    cout << n - (tmp == s);
  }
} 


