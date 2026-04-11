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
  int n, T;
  cin >> n >> T;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  set<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    st.insert({a[i], 0});
  }

  int cur = 0, prv = 0, ans = 0;
  st.insert({0, 1});
  st.insert({T, 0});
  while (st.size()) {
    auto [t, state] = *st.begin();
    st.erase(st.begin());

    ans += (t - prv) * cur;
    if (t == T) {
      break;
    }
    if (cur == 1 && state == 0) {
      st.insert({t + 100, 1});
    }
    cur = state;
    prv = t;
  }

  cout << ans << '\n';
}
