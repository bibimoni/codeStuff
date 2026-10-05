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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto find_near = [&](vector<int> h) -> vector<int> {
    stack<int> st;
    vector<int> ret(n, -1);
    for (int i = 0; i < n; i++) {
      while (st.size() && h[st.top()] <= h[i]) {
        st.pop();
      }

      if (st.size()) {
        ret[i] = st.top();
      }
      st.push(i);
    }
    return ret;
  };

  auto l = find_near(a);

  auto b = a;
  reverse(b.begin(), b.end());
  auto r = find_near(b);
  for (int i = 0; i < n; i++) {
    if (r[i] != -1)
      r[i] = n - r[i] - 1;
  }
  reverse(r.begin(), r.end());

  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) -> int {
    return a[i] > a[j];
  });

  vector<int> dp(n, 1);
  for (int i = 0; i < n; i++) {
    if (l[id[i]] != -1) {
      dp[id[i]] = max(dp[id[i]], dp[l[id[i]]] + 1);
    }
    if (r[id[i]] != -1) {
      dp[id[i]] = max(dp[id[i]], dp[r[id[i]]] + 1);
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}
