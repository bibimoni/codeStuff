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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  multiset<int> st;
  int q;
  cin >> q;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x;
      cin >> x;
      st.insert(x);
    } else {
      cout << (*st.begin()) << '\n';
      st.erase(st.begin());
    }
  }
}
