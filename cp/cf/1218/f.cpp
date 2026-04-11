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

  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int a;
  cin >> a;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  int ans = 0;
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    if (ans == -1) {
      break;
    }
    st.insert(c[i]);
    while (st.size() && k < x[i]) {
      k += a;
      ans += *st.begin();
      st.erase(st.begin());
    }
    if (k < x[i]) {
      ans = -1;
    }
  }

  cout << ans << '\n';
}
