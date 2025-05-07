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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    bool ok = true, hasOne = false;;
    for (int i = 1; i <= n; i++) {
      hasOne |= s[i] == '1';
      if (s[i] != t[i] && s[i] == '0') {
        ok &= hasOne;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


