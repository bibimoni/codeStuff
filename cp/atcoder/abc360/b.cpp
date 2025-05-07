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
  string t, s;
  cin >> s >> t;
  bool ok = false;
  for (int w = 1; w < s.size(); w++) {
    for (int c = 1; c <= w; c++) {
      string tmp = "";
      int idx = c;
      while (idx <= s.size()) {
        tmp += s[idx - 1];
        idx += w;
      }
      ok |= tmp == t;
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
}


