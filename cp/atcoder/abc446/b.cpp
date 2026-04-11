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
  int n, m;
  cin >> n >> m;
  set<int> st;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    bool ok = false;
    for (int j = 0; j < l; j++) {
      int x;
      cin >> x;
      if (st.find(x) != st.end()) {
        continue;
      }
      if (!ok) {
        cout << x << '\n';
        st.insert(x);
      }
      ok = true;
    }
    if (!ok) {
      cout << "0\n";
    }
  }
}
