#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long maxTotalValue(vector<int> &a, int k) {
    map<int, vector<int>> mp;
    int n = int(a.size());
    vector<int> lmx(n), rmx(n), lmn(n), rmn(n);
    stack<int> st, stp;
    for (int i = 0; i < n; i++) {
      while (st.size() && a[st.top()] < a[i]) {
        st.pop();
      }
      while (stp.size() && a[stp.top()] > a[i]) {
        stp.pop();
      }
      lmx[i] = st.size() ? st.top() : 0;
      lmn[i] = stp.size() ? stp.top() : 0;
    }
    st = stack<int>();
    stp = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
      while (st.size() && a[st.top()] < a[i]) {
        st.pop();
      }
      while (stp.size() && a[stp.top()] > a[i]) {
        stp.pop();
      }
      rmx[i] = st.size() ? st.top() : n;
      rmn[i] = stp.size() ? stp.top() : n;
    }

    set<pair<int, int>> s1;
    set<pair<int, int>, greater<pair<int, int>>> s2;

    for (int i = 0; i < n; i++) {
      s1.insert({a[i], (i - lmn[i]) * (rmn[i] - i)});
      s2.insert({a[i], (i - lmx[i]) * (rmx[i] - i)});
    }

    int64_t ans = 0;
    for (int kk = 0; kk < k; kk++) {
      auto [mn, len] = *s1.begin();
      s1.erase(s1.begin());
      auto [mx, lex] = *s2.begin();
      s2.erase(s2.begin());

      ans += mx - mn;
      len -= 1;
      lex -= 1;
      if (len) {
        s1.insert({mn, len});
      }
      if (lex) {
        s2.insert({mx, lex});
      }
    }
    return ans;
  }
};
