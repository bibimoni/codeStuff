/**
 * Author: distiled
 */
#include <algorithm>
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
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    stack<char> st;
    int n = s.size();
    auto pls = [&]() -> bool {
      bool ok = false;
      for (int i = 0; i < n; i++) {
        st.push(s[i]);
        int cnt = 0;
        while (st.size() > 2) {
          char c1 = st.top();
          st.pop();
          char c2 = st.top();
          st.pop();
          char c3 = st.top();
          if (c3 == 'p' && c1 == 'p' && c2 == 't') {
            st.pop();
            cnt += 1;
          } else {
            st.push(c2);
            st.push(c1);
            break;
          }
        }
        ok |= cnt > 0;
        while (cnt--) {
          st.push('a');
          st.push('p');
        }
      }
      return ok;
    };
    bool gogo = false;
    while (true) {
      for (int i = 0; i < n; i++) {
        if (i < n - 1 && s[i] == 'a' && s[i + 1] == 'p') {
          int cnt = 0;
          while (st.size() > 1) {
            char c1 = st.top();
            st.pop();
            char c2 = st.top();
            if (c1 == 't' && c2 == 'p') {
              st.pop();
              cnt += 1;
            } else {
              st.push(c1);
              break;
            }
          }
          gogo |= cnt > 0;
          while (cnt--) {
            st.push('a');
          }
          i += 1;
          st.push('a');
          st.push('p');
          continue;
        } else {
          st.push(s[i]);
        }
      }
      s.clear();
      while (st.size()) {
        s.push_back(st.top());
        st.pop();
      }
      reverse(s.begin(), s.end());
      n = s.size();
      gogo |= pls();
      s.clear();
      while (st.size()) {
        s.push_back(st.top());
        st.pop();
      }
      reverse(s.begin(), s.end());
      n = s.size();
      if (!gogo) {
        break;
      }
      gogo = false;
    }
    dbg(s);
    cout << s.size() << '\n';
  }
}
