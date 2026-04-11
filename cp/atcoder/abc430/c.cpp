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
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  s = " " + s;
  vector<int> pa(n + 1);
  vector<int> pb(n + 1);
  for (int i = 1; i <= n; i++) {
    pa[i] = pa[i - 1] + int(s[i] == 'a');
    pb[i] = pb[i - 1] + int(s[i] == 'b');
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int lo = 1, hi = i, mxb = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (pb[i] - pb[mid - 1] >= b) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
        mxb = mid;
      }
    }
    lo = 1, hi = i;
    int mxa = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (pa[i] - pa[mid - 1] < a) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
        mxa = mid;
      }
    }
    dbg(i, mxa, mxb);
    if (mxa != -1 && mxb != -1) {
      ans += max(int(0), mxa - mxb + 1);
    }
  }

  cout << ans << '\n';
}
