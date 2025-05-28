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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int, int> mp;
  for (int &i : a) {
    cin >> i;
    mp[i] += 1;
  }
  bool ok = mp.size() == m;
  if (!ok) {
    cout << "0\n";
    return 0;
  }
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += 1;
    if (mp[a[i]] - 1 == 0) {
      break;
    }
    mp[a[i]] -= 1;
  }
  cout << ans << '\n';
}
