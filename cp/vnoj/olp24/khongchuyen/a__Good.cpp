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
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  int half = n / 2;
  int cnt_sol = 0, idx = -1;
  for (int i = 1; i <= n; i++) {
    string tt = s.substr(1, i - 1) + s.substr(i + 1);
    dbg(tt, i, s, tt.substr(0, tt.size() / 2), tt.substr(tt.size() / 2));
    if (tt.substr(0, tt.size() / 2) == tt.substr(tt.size() / 2)) {
      cnt_sol += 1;
      idx = i;
    }
  }

  if (cnt_sol == 0) {
    cout << "No Solution";
  } else if (cnt_sol == 1) {
    string ans;
    for (int i = 1; i <= n; i++) {
      if (idx == i) {
        continue;
      }
      ans += s[i];
    }
    cout << ans.substr(ans.size() / 2);
  } else {
    cout << "Multiple Solutions";
  }
}


