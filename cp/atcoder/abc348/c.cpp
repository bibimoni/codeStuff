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
  int n;
  cin >> n;
  stack<int> st;
  auto peek = [&]() -> bool {
    if (st.size() < 4) {
      return false;
    }

    stack<int> cur;
    int prev = st.top(), ok = true;
    int cnt = 4;
    while (cnt--) {
      if (prev != st.top()) {
        ok = false;
      }
      cur.push(st.top());
      st.pop();
    }
    while (cur.size()) {
      st.push(cur.top());
      cur.pop();
    }
    return ok;
  };

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.push(x);
    if (peek()) {
      int cnt = 4;
      while (cnt--) {
        st.pop();
      }
    }
  }

  cout << st.size();
}
