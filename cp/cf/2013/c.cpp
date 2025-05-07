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
    auto ask = [&] (string t) -> int {
      cout << "? " << t << '\n';
      cout.flush();
      int ret;
      cin >> ret;
      return bool(ret);
    };
    string ans = "";
    bool reach_end = false;
    for (int i = 0; i < 2 * n; i++) {
      if (ans.size() == n) {
        break;
      }
      if (!reach_end) {
        string t = ans + "0";
        if (ask(t)) {
          ans += "0";
          continue;
        } else {
          t = ans + "1";
          if (!ask(t)) {
            reach_end = true;
            continue;
          }
          ans += "1";
          continue;
        }
      } else {
        string t = "0" + ans;
        if (ask(t)) {
          ans = "0" + ans;
        } else {
          ans = "1" + ans;
        }
      }
    }
    cout << "! " << ans << '\n'; 
    cout.flush();
  }
}


