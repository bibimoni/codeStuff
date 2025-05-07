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
    int cur = 0;
    for (int i = 0; i + 3 < int(s.size()); i++) {
      cur += s.substr(i, 4) == "1100";
    }
    int q;
    cin >> q;
    while (q--) {
      int id, v;
      cin >> id >> v;
      id -= 1;
      for (int i = max(id - 3, int(0)); i < min(id + 3, int(s.size() - 3)); i++) {
        cur -= s.substr(i, 4) == "1100";
      }
      s[id] = v + '0';
      for (int i = max(id - 3, int(0)); i < min(id + 3, int(s.size() - 3)); i++) {
        cur += s.substr(i, 4) == "1100";
      }
      cout << (cur > 0 ? "YES\n" : "NO\n");
    }
  }
}


