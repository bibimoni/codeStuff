/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <cmath>
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
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  int sz = int(a.size());
  for (int i = 0; i < sz; i++) {
    a.push_back(a[i]);
  }

  int cur = 0, j = 0;
  while (cur < c) {
    cur += cnt[a[j]];
    j += 1;
  }

  int prev = 0, ans = cur;
  for (int i = 0; i < sz; i++) {
    ans += (a[i] - prev) * cur;
    prev = a[i];
    cur -= cnt[a[i]];
    while (cur < c) {
      cur += cnt[a[j]];
      j += 1;
    }
  }

  ans += (m - 1 - prev) * cur;

  cout << ans << '\n';
}
