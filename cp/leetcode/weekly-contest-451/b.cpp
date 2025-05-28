#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string resultingString(string s) {
    int n = s.size();
    auto chk = [&] (char c1, char c2) -> bool {
      if (c1 > c2) {
        swap(c1, c2);
      }
      return c2 - c1 == 1 || c2 == 'z' && c1 == 'a';
    };

    stack<char> st;
    for (int i = 0; i < n; i++) {
      if (st.size() && chk(st.top(), s[i])) {
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    string res = "";
    while (st.size()) {
      res += string(1, st.top());
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
