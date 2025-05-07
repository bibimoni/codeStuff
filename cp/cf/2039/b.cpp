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
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    bool ok = false;
    string ans = "";
    for (int len = 2; len <= min((int)s.size(), int(3)); len++) {
      for (int i = 0; i + len - 1 < s.size(); i++) {
        string t = s.substr(i, len);
        set<string> st;
        for (int beg = 0; beg < t.size(); beg++) {
          for (int end = beg; end < t.size(); end++) {
            st.insert(t.substr(beg, end - beg + 1));
          }
        }
        if (st.size() % 2 == 0) {
          ans = t;
          ok = true;
        }
      }
    }
    if (ok) {
      cout << ans << '\n';
    } else {
      cout << "-1\n";
    }
  }
}


