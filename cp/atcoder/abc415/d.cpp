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
  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }

  vector<pair<int, int>> s;
  for (int i = 0; i < m; i++) {
    s.push_back({a[i], -a[i] + b[i]});
  }
  sort(s.begin(), s.end(), [&](auto i, auto j) {
    if (i.first != j.first) {
      return i.first < j.first;
    } else {
      return i.second > j.second;
    }
  });

  vector<int> best(m);
  int cur = s[0].second;
  for (int i = 1; i < m; i++) {
    if (cur < s[i].second) {
      cur = s[i].second;
      best[i] = i;
    } else {
      best[i] = best[i - 1];
    }
  }

  int ans = 0;
  cur = n;
  while (true) {
    int lo = 0, hi = m - 1, ret = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (s[mid].first <= cur) {
        lo = mid + 1;
        ret = mid;
      } else {
        hi = mid - 1;
      }
    }

    if (ret == -1) {
      break;
    }

    int idx = best[ret];
    int tt = (s[idx].first - cur) / s[idx].second;
    tt = max(tt, int(1));
    cur += tt * s[idx].second;
    ans += tt;
  }
  cout << ans << '\n';
}
