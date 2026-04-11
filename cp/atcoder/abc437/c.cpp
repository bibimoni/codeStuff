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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> w(n), p(n);
    vector<int64_t> st;
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> w[i] >> p[i];
      sum += p[i];
      st.push_back(p[i] + w[i]);
    }
    sort(st.begin(), st.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (sum - st[i] >= 0) {
        ans += 1;
        sum -= st[i];
      }
    }
    cout << ans << '\n';
  }
}
