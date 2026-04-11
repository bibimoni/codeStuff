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
    vector<int> odd;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x % 2 != 0)
        odd.push_back(x);
      else
        ans += x;
    }

    if (odd.size() == 0) {
      cout << "0\n";
      continue;
    }

    sort(odd.begin(), odd.end(), greater<int>());
    for (int i = 0, l = 0; i < (int)odd.size(); i++) {
      if (i % 2 == 0) {
        ans += odd[l];
        l += 1;
      }
    }

    cout << ans << '\n';
  }
}
