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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  vector<vector<int>> rev(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    rev[a[i]].push_back(i);
  }

  vector<int> flg(n + 1, -2);
  map<int, int> cyclId;
  map<int, int> cyclSz;
  map<pair<int, int>, int> cyclSum;
  map<pair<int, int>, int> v;
  int loop_cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (flg[i] != -2) {
      continue;
    }

    vector<int> path{i};
    int cur = i;
    flg[cur] = -3;
    while (flg[a[cur]] == -2) {
      cur = a[cur];
      flg[cur] = -3;
      path.push_back(cur);
    }

    bool ok = false;
    int id = 0, sum = 0;
    for (int j : path) {
      ok |= a[cur] == j;
      flg[j] = ok ? loop_cnt : -1;
      if (ok) {
        id += 1;
        sum += j;
        cyclId[j] = id;
        cyclSum[{id, flg[j]}] = sum;
        v[{id, flg[j]}] = j;
      }
    }

    cyclSz[loop_cnt] = id;
    loop_cnt += 1;
  }
  dbg(cyclId, cyclSz, cyclSum);
  dbg(flg);

  vector<int> d(n + 1), r(n + 1), w(n + 1);
  const int LG = 20;

  vector<vector<int>> up(n + 1, vector<int>(LG + 1));
  for (int i = 1; i <= n; i++) {
    if (!(flg[i] == -1 && flg[a[i]] != -1)) {
      continue;
    }

    auto dfs = [&](auto &&self, int u, int p) -> void {
      w[u] += u;
      r[u] = a[i];
      up[u][0] = p;
      for (int lg = 1; lg <= LG; lg++) {
        up[u][lg] = up[up[u][lg - 1]][lg - 1];
      }
      for (int v : rev[u]) {
        d[v] = d[u] + 1;
        w[v] += w[u];
        self(self, v, u);
      }
    };

    d[i] = 0; // jump 1 to cycle
    dfs(dfs, i, a[i]);
  }

  dbg(d, r, w);

  auto ansc = [&](int u, int k) -> int {
    for (int j = 0; (1 << j) <= k; j++) {
      if ((k >> j) & 1)
        u = up[u][j];
    }
    return u;
  };

  auto cycle = [&](int u, int op) -> int {
    dbg(u, op);
    if (op == 0) {
      return 0;
    }
    assert(flg[u] != -1);
    int sz = cyclSz[flg[u]];
    if (sz == 1) {
      return op * cyclSum[{sz, flg[u]}];
    }
    int cntloop = op / sz;
    dbg(cntloop);
    int cur = cntloop * cyclSum[{sz, flg[u]}];
    op -= cntloop * sz;
    if (op == 0) {
      return cur;
    }
    dbg("op after", op);
    int lo = cyclId[u], hi = cyclId[v[{((lo + op - 1) - 1) % sz + 1, flg[u]}]];
    dbg(lo, hi);
    if (lo <= hi) {
      cur += cyclSum[{hi, flg[u]}] - cyclSum[{lo - 1, flg[u]}];
    } else {
      cur += cyclSum[{sz, flg[u]}] - cyclSum[{lo - 1, flg[u]}] +
             cyclSum[{hi, flg[u]}];
    }
    dbg(cur);
    return cur;
  };

  while (q--) {
    int t, b;
    cin >> t >> b;
    dbg(t, b);
    int nxt, ans = 0;
    if (flg[b] == -1) {
      if (t <= d[b]) {
        nxt = ansc(b, t);
        cout << w[b] - w[nxt] << '\n';
        continue;
      }
      ans = w[b];
      t -= d[b] + 1;
      nxt = r[b];
    } else {
      nxt = b;
    }
    ans += cycle(nxt, t);
    cout << ans << '\n';
  }
}
