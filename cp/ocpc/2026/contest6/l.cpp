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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<int> st, ost;
  for (int i = 0; i * 2 < n; i++) {
    if (s[i] == s[n - i - 1]) {
      if (s[i] == '1') {
        ost.insert(i);
        ost.insert(n - i - 1);
      }
    } else {
      if (s[i] == '1') {
        st.insert(i);
      } else {
        st.insert(n - i - 1);
      }
    }
  }

  auto solve = [&] () -> void {
    if (!st.size()) {
      cout << "0 ";
      return;
    }

    int r = *st.rbegin(), l = *st.begin();
    if (!ost.size()) {
      cout << r - l + 1 << ' ';
      return;
    }
    auto l1 = ost.lower_bound(l);
    if (l1 == ost.end() || *l1 > r) {
      cout << r - l + 1 << ' ';
      return;
    }
    auto r1 = ost.upper_bound(r);
    if (r1 == ost.begin()) {
      cout << r - l + 1 << ' ';
      return;
    }
    r1--;
    int r2 = n - *l1 - 1;
    int l2 = n - *r1 - 1;
    r = max(r, r2);
    l = min(l, l2);
    cout << r - l + 1 << ' ';
  };

  solve();
  int q;
  cin >> q;
  while (q--) {
    int i;
    cin >> i;
    i -= 1;
    if (s[i] != s[n - i - 1]) {
      if (s[i] == '1') {
        st.erase(i);
      } else {
        st.erase(n - i - 1);
      }
    } else if (s[i] == '1') {
      ost.erase(i);
      ost.erase(n - i - 1);
    }
    s[i] = '1' - s[i] + '0';
    if (s[i] != s[n - i - 1]) {
      if (s[i] == '1') {
        st.insert(i);
      } else {
        st.insert(n - i - 1);
      }
    } else if (s[i] == '1') {
      ost.insert(i);
      ost.insert(n - i - 1);
    }
    solve();
  }
}
