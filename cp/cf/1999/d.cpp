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
    int n = int(s.size()), m = int(t.size());
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (j < m && (s[i] == t[j] || s[i] == '?')) {
        if (s[i] == '?') {
          s[i] = t[j];
        }
        j += 1;
      } 
      if (j == m && s[i] == '?') {
        s[i] = 'a';
      }
    }
    if (j != m) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << s << '\n';
    }

  }
}


