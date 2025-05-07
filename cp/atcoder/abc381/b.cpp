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
  if (s.size() % 2 != 0) {
     cout << "No\n";
     return 0;
  }
  bool ok = true;
  set<char> st;
  for (int i = 0; i < (int)s.size(); i += 2) {
    if (st.find(s[i]) != st.end() || s[i] != s[i + 1]) {
      ok = false;
    }
    st.insert(s[i]);
  }
  cout << (ok ? "Yes\n" : "No\n");
}


