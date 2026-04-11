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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int ans = 0;
    multiset<int> st{b.begin(), b.end()};
    for (int i = 0; i < n; i++) {
      auto it = st.lower_bound(m - a[i]);
      if (it == st.end()) {
        it = st.begin();
      }
      ans += (a[i] + *it) % m;
      st.erase(it);
    }
    cout << ans << '\n';
  }
}
