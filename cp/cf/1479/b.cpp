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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0, last_1 = 0, last_2 = 0;
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i < n; i++) {
    pos[a[i]].push_back(i);
  }
  for (int i = 0; i <= n; i++) {
    pos[i].push_back(n);
  }
  for (int i = 0; i < n; i++) {
    if (last_2 == a[i] || last_1 == a[i]) {
      if (last_2 == a[i]) {
        ans += last_1 != a[i];
        last_1 = a[i];
      } else {
        ans += last_2 != a[i];
        last_2 = a[i];
      }
    } else {
      int nxt_1 = *upper_bound(pos[last_1].begin(), pos[last_1].end(), i);
      int nxt_2 = *upper_bound(pos[last_2].begin(), pos[last_2].end(), i);
      if (nxt_2 < nxt_1) {
        last_2 = a[i];
      } else {
        last_1 = a[i];
      }
      ans += 1;
    }
  }
  cout << ans << '\n';
}

