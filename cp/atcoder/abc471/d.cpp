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
  int q, v;
  cin >> q >> v;
  
  multiset<int, greater<int>> st;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int t, w;
      cin >> t >> w;
      st.insert(w - t);
    } else {
      int t;
      cin >> t;

      if (!st.size()) {
        cout << "-1\n";
        continue;
      }

      auto val = *st.begin();
      st.erase(st.begin());
      cout << min(v, val + t) << '\n';
    }
  }
}
