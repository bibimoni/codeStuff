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
  int cur = 147;
  auto dfs = [&](auto &&self, int d, int i, vector<int> ds) -> int {
    set<int> st;
    ds.push_back(d);
    int cnt = 0;
    for (; i <= 200;) {
      if (st.find(i) != st.end() || st.find(i + d) != st.end()) {
        int v = 0;
        for (int nd = 1; nd <= 200; nd++)  {
          int x = self(self, nd, *st.rbegin() + 1, ds);
          if (v < x) {
            v = x;
          }
        }
        return v + cnt;
      }
      if (2 * i + d <= cur) {
        cur += 1;
        cnt += 1;
        st.insert(i);
        st.insert(i + d);
      }
      i += 1;
    }
    return cnt;
  };

  for (int i = 1; i <= 100; i++) {
    vector<int> d;
    dbg(dfs(dfs, i, 1, d));
  }
}
