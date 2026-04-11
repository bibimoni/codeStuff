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
  int n;
  cin >> n;

  set<int> st;
  st.insert(0);
  int ans = 0;
  map<int, int> mp;
  mp[0] = 1e18;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    dbg(x);
    st.insert(x);
    auto it = st.lower_bound(x);

    int l = *prev(it);
    if (abs(l - mp[l]) > abs(l - x)) {
      if (mp[l] != (int)1e18) {
        ans -= abs(l - mp[l]);
      }
      mp[l] = x;
      ans += abs(l - x);
    }
    dbg(ans, l, mp[l]);
    auto itr = next(it);
    if (itr != st.end()) {
      int r = *itr;
      dbg(r);
      if (abs(r - mp[r]) > abs(r - x)) {
        ans -= abs(r - mp[r]);
        mp[r] = x;
        ans += abs(r - x);
      }
      if (abs(x - l) > abs(x - r)) {
        mp[x] = r;
        ans += abs(x - r);
      } else {
        mp[x] = l;
        ans += abs(x - l);
      }
    } else {
      ans += abs(x - l);
      mp[x] = l;
    }

    cout << ans << "\n";
  }
}
