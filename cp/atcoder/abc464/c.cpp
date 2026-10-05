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
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), d(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> d[i] >> b[i];
  }

  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]] += 1;
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return d[i] < d[j];
  });

  int cur = 0, ans = (int)mp.size();
  for (int i = 1; i <= m; i++) {
    while (cur < n && d[p[cur]] == i) {
      mp[a[p[cur]]] -= 1;
      if (mp[a[p[cur]]] == 0) {
        ans -= 1;
      }
      mp[b[p[cur]]] += 1;
      if (mp[b[p[cur]]] == 1) {
        ans += 1;
      }
      cur += 1;
    } 
    cout << ans  << '\n';
  }
}
