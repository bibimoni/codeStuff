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

  vector<vector<int>> ga(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    ga[u].push_back(v);
    ga[v].push_back(u);
  }

  vector<vector<int>> gb(m + 1);
  for (int i = 0; i < m - 1; i++) {
    int u, v;
    cin >> u >> v;
    gb[u].push_back(v);
    gb[v].push_back(u);
  }

  auto find_d = [&](vector<vector<int>> &g, int ns) -> vector<int> {
    vector<int> ret(ns + 1);
    if (ns == 1) {
      return ret;
    }
    assert(ns > 1);
    auto dfs = [&](auto &&self, int u, int p, vector<int> &d) -> void {
      for (int v : g[u]) {
        if (v == p) {
          continue;
        }
        d[v] = d[u] + 1;
        self(self, v, u, d);
      }
    };

    vector<int> d(ns + 1);
    dfs(dfs, 1, 1, d);
    int node = max_element(d.begin(), d.end()) - d.begin();

    d = vector<int>(ns + 1);
    dfs(dfs, node, node, d);
    int node2 = max_element(d.begin(), d.end()) - d.begin();

    vector<int> d2(ns + 1);
    dfs(dfs, node2, node2, d2);
    for (int u = 1; u <= ns; u++) {
      ret[u] = max(d[u], d2[u]);
    }
    return ret;
  };

  auto da = find_d(ga, n);
  auto db = find_d(gb, m);
  int mxa = *max_element(da.begin() + 1, da.end());
  int mxb = *max_element(db.begin() + 1, db.end());
  int mxd = max(mxa, mxb);

  sort(db.begin(), db.end());
  vector<int> pdb(m + 1);
  for (int i = 1; i <= m; i++) {
    pdb[i] = pdb[i - 1] + db[i];
  }
  int ans = 0;
  for (int u = 1; u <= n; u++) {
    int lo = 1, hi = m, ret = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (mxd > da[u] + db[mid] + 1) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
        ret = mid;
      }
    }
    if (ret == -1) {
      ans += m * mxd;
    } else {
      ans += (m - ret + 1) * da[u] + pdb[m] - pdb[ret - 1] + (m - ret + 1) +
             (ret - 1) * mxd;
    }
  }

  cout << ans << '\n';
}
