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

  int n;
  cin >> n;

  vector<int> a(n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int cur = 0;
  for (int i = 0; i < n; i++) {
    int r, g, d;
    cin >> r >> g >> d;

    cur += a[i];
    dbg(cur);
    int k = (int)ceil(double(cur + d - g) / double(r + g));
    if (!((cur + d - g) % (r + g)))
      k++;
    cur = max(cur, -d + k * (r + g));

    dbg(k);
    dbg(cur);
  }

  cout << cur << endl;
}
