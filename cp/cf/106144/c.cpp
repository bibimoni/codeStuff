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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s[0] == ')' && s[n - 1] == ')') {
      cout << "Polycarp\n";
      continue;
    }

    const int inf = 1e9;
    s = " " + s + " ";
    auto f = [&] (int i) -> int {
      return s[i] == '(' ? 1 : -1;
    };

    auto dfs = [&](auto &&self, int i, int j) -> bool {
      if (i == j) {

      }
    };
  }
}
