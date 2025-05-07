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
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin() + 1, a.end());
  int ans = 0, cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i].second - (a[i].first - a[i - 1].first);
    cur = max(cur, a[i].second);
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}

