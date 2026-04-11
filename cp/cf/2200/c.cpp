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
    int n;
    string s;
    cin >> n >> s;
    stack<char> st;
    for (char c : s) {
      if (!st.size()) {
        st.push(c);
      } else {
        if (st.top() == c) {
          st.pop();
        } else {
          st.push(c);
        }
      }
    }

    cout << (st.size() == 0 ? "YES\n" : "NO\n");
  }
}
