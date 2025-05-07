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
    string s, t;
    cin >> s >> t;
    int ans = 0;
    bool copy = false;
    for (int i = 0; i < min(s.size(), t.size()); i++) {
      if (s[i] != t[i]) {
        break;
      }
      copy = true;
      ans += s[i] == t[i];
    }
    int id = ans;
    for (int i = id; i < s.size(); i++) {
      ans += 1;
    }
    for (int i = id; i < t.size(); i++) {
      ans += 1;
    }
    cout << ans + int(copy) << '\n';
  }
}


