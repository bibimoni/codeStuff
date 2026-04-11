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
  int n;
  cin >> n;
  vector t(n, 0);
  vector<vector<int>> rev(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    t[i] -= 1;
    rev[t[i]].push_back(i);
  }

  vector flg(n, -2);
  map<int, int> cycl_size;
  int cycl_cnt = 0;
  for (int i = 0; i < n; i++) {
    if (flg[i] != -2) {
      continue;
    }

    vector<int> path{i};
    int cur = i;
    flg[cur] = -3;
    while (flg[t[cur]] == -2) {
      cur = t[cur];
      flg[cur] = -3;
      path.push_back(cur);
    }

    bool ok = false;
    for (int j : path) {
      ok |= t[cur] == j;
      flg[j] = ok ? cycl_cnt : -1;
      cycl_size[cycl_cnt] += int(ok);
    }

    cycl_cnt += 1;
  }

  vector<int> d(n), r(n);
  iota(r.begin(), r.end(), 0);
  for (int i = 0; i < n; i++) {
    if (!(flg[i] == -1 && flg[t[i]] != -1)) {
      continue;
    }

    auto dfs = [&](auto &&self, int u, int p) -> void {
      r[u] = t[i];
      d[u] = d[p] + 1;
      for (int v : rev[u]) {
        if (v == p) {
          continue;
        }
        self(self, v, u);
      }
    };

    dfs(dfs, i, t[i]);
  }

  for (int i = 0; i < n; i++) {
    int ans = 0, cur = i;
    if (flg[i] == -1) {
      ans += d[i];
      cur = r[cur];
    }
    ans += cycl_size[flg[cur]];
    cout << ans << " \n"[i == n - 1];
  }
}
