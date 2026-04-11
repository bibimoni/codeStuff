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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    set<int> st;
    for (int i = 0; i < n; i++) {
      if (a[i] >= k) {
        break;
      }
      st.insert(a[i]);
    }

    int cnt = k - int(st.size());

    int ans = 0, same = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == k) {
        same += 1;
      }
    }

    int val = min(same, cnt);
    cnt -= val;
    same -= val;
    ans += cnt + same + val;
    cout << ans << '\n';
  }
}
