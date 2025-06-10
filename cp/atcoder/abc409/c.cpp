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
  int n, l;
  cin >> n >> l;
  vector<int> mark(l);
  int st = 0;
  mark[st] = 1;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    mark[(x + st) % l] += 1;
    st += x;
  }
  dbg(mark);
  if (l % 3 != 0) {
    cout << "0";
  } else {
    int ans = 0;
    for (int i = 0; i * 3 < l; i++) {
      ans += (mark[i] * mark[i + l / 3] * mark[i + 2 * l / 3]);
    }
    cout << ans;
  }
}
