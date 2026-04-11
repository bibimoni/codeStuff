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
  int n, k;
  cin >> n >> k;
  vector<array<int, 3>> a;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a.push_back({i, u, v});
  }

  sort(a.begin(), a.end(),
       [&](const auto &i, const auto &j) { return i[2] < j[2]; });

  vector<int> ans(n), cnt(32);
  for (auto p : a) {
    int id = p[0], l = p[1], r = p[2];
    int day = -1;
    for (int j = l; j <= r; j++) {
      if (cnt[j] >= k) {
        continue;
      }
      day = j;
      break;
    }

    ans[id] = day;
    cnt[day] += 1;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
}
