/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b;
    cin >> a >> b;
    auto conv = [&](string &t) -> string {
      string ret = "";
      for (char c : t) {
        ret += c;
        while (ret.back() == ')' && ret.size() >= 4 &&
               ret.substr(ret.size() - 4, 4) == "(xx)") {
          for (int k = 0; k < 4; k++) {
            ret.pop_back();
          }
          ret += "xx";
          dbg(ret);
        }
      }
      return ret;
    };

    auto x = conv(a);
    auto y = conv(b);
    cout << (x == y ? "Yes\n" : "No\n");
  }
}
