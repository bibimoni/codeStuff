// time-limit: 3000
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    stack<int> st;
    int ans = 0, sum_mn = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      while (st.size() && a[st.top()] >= a[i]) {
        int id = st.top();
        st.pop();
        if (st.size()) {
          sum_mn -= a[id] * (id - st.top());
        } else {
          sum_mn -= a[id] * id;
        }
      }
      if (st.size()) {
        sum_mn += a[i] * (i - st.top());
      } else {
        sum_mn += a[i] * i;
      }
      st.push(i);
      sum += a[i];
      ans += sum + (a[i] * i) - 2 * sum_mn;
    }
    cout << ans << '\n';
  }
}
