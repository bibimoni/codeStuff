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
  int h, w, n;
  cin >> h >> w >> n;
  vector a(h, vector<int>(w));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];

  set<int> b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.insert(x);
  }

  int mx = 0;
  for (int i = 0; i < h; i++) {
    int cnt = 0;
    for (int j : a[i]) {
      cnt += b.find(j) != b.end();
    }
    mx = max(cnt, mx);
  }

  cout << mx << '\n';
}
