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
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    set<char> st;
    for(char c : s) {
      st.insert(c);
    }
    if(st.size() == 1) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
      for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] != s[i + 1]) {
          swap(s[i], s[i + 1]);
          break;
        }
      }
      cout << s << '\n';
    }
  }
}


