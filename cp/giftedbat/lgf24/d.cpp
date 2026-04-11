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

class Dsu {
  vector<int> parent, siz;
  int count_cp;
  vector<int> has;

public:
  int best;
  Dsu() {}

  Dsu(int n) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
    parent.resize(n);
    siz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
    has.resize(n);
    best = 0;
  }

  void add(int u) {
    has[u] += 1;
    best = max(has[u], best);
  }

  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find(parent[v]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (!has[a] || !has[b]) {
      return false;
    }
    if (a != b) {
      if (siz[a] < siz[b]) {
        swap(a, b);
      }
      parent[b] = a;
      siz[a] += siz[b];
      count_cp -= 1;
      has[a] += has[b];
      best = max(best, has[a]);
      return true;
    } else {
      return false;
    }
  }

  int size(int u) { return siz[find(u)]; }

  int size() { return count_cp; }

  bool same(int u, int v) { return find(u) == find(v); }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l, r;
  cin >> n >> m >> l >> r;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  auto check = [&](int cmp) -> bool {
    vector<int> h(m + 1);
    for (int low = 1; low <= n; low++) {
      for (int j = 1; j <= m; j++) {
        h[j] = ((a[low][j] & cmp) == cmp) ? h[j] + 1 : 0;
      }
      vector<vector<int>> pos(n + 1);
      for (int j = 1; j <= m; j++) {
        pos[h[j]].push_back(j);
      }

      Dsu dsu(m + 1);
      for (int i = n; i >= 1; i--) {
        for (auto j : pos[i]) {
          dsu.add(j);
          if (j > 1) {
            dsu.unite(j, j - 1);
          }
          if (j < m) {
            dsu.unite(j, j + 1);
          }
        }

        int best = min(dsu.best, r / i);
        if (best * i >= l) {
          return 1;
        }
      }
    }
    return 0;
  };

  int ans = 0;
  for (int j = 30; j >= 0; j--) {
    if (check(ans | (1 << j))) {
      ans |= 1 << j;
    }
  }

  cout << ans << '\n';
}
