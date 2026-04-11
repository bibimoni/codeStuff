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
  int q;
  cin >> q;
  multiset<int> st;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int h;
      cin >> h;
      st.insert(h);
    } else if (opt == 2) {
      int h;
      cin >> h;
      auto it = st.begin();
      while (it != st.end()) {
        auto nit = next(it);
        if ((*it) <= h) {
          st.erase(it);
        } else {
          break;
        }
        it = nit;
      }
    }

    cout << int(st.size()) << '\n';
  }
}
