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

int a[21];
int ans = -1e18;
int n;
void recursion(int i, int cnt, int val) {
  if (i == n) {
    if (cnt % 2 == 0) {
      return;
    }
    ans = max(ans, val);
    return;
  }
  recursion(i + 1, cnt + 1, val + a[i]);
  recursion(i + 1, cnt, val);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  recursion(0, 0, 0);
  cout << ans << '\n';
}
