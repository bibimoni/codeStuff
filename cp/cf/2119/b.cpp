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
    int px, py, qx, qy;
    cin >> px >> py >> qx >> qy;

    int sa = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sa += a[i];
    }

    int dist = (px - qx) * (px - qx) + (py - qy) * (py - qy);

    if (dist > sa * sa) {
      cout << "No\n";
      continue;
    }

    int mxa = *max_element(a.begin(), a.end());
    int s = 2 * mxa - sa;
    dbg(dist, s, sa, mxa);
    cout << ((s > 0 && s * s > dist) ? "No\n" : "Yes\n");
  }
}
