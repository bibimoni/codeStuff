/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#define table(...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int64_t> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    c[i] += c[i - 1];
  }

  int64_t ans = -1e18;
  deque<int64_t> dq;
  for (int i = a; i <= n; i++) {
    while (dq.size() && c[dq.back()] >= c[i - a]) {
      dq.pop_back();
    }

    dq.push_back(i - a);

    if (dq.front() < i - b) {
      dq.pop_front();
    }

    if (dq.size()) {
      ans = max(ans, c[i] - c[dq.front()]);
    }
  }

  cout << ans << '\n';
}
