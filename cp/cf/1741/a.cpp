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
    string s, t;
    cin >> s >> t;
    auto calc = [&] (string &str) -> int {
      if(str == "M")
        return 0;
      int cnt = str.size();
      return cnt * (str[str.size() - 1] == 'L' ? 1 : -1);
    };
    if(calc(s) < calc(t)) {
      cout << "<\n";
    }
    else if(calc(s) > calc(t)) {
      cout << ">\n";
    }
    else {
      cout << "=\n";
    }
  }
}


