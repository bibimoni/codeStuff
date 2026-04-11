/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

template <class T> class Fenwick {
  vector<T> a;
  int n;

public:
  Fenwick() {}

  Fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n + 5, static_cast<T>(0));
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q += a[r]; // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] += del; // check update rule
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<pair<int, int>> edges(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges[i] = {u, v};
  }

  vector<int> st(n + 1), ed(n + 1), d(n + 1);
  int ord = 0;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    ord += 1;
    st[u] = ord;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      d[v] = d[u] + 1;
      self(self, v, u);
    }
    ed[u] = ord;
  };

  dfs(dfs, 1, 1);

  Fenwick<int> ft(n + 1);
  for (int i = 1; i <= n; i++) {
    ft.update(i, 1);
  }

  vector<int> ans;

  int q;
  cin >> q;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x, w;
      cin >> x >> w;
      ft.update(st[x], w);
    } else {
      int y;
      cin >> y;
      auto [u, v] = edges[y];
      if (d[u] > d[v]) {
        swap(u, v);
      }
      int all = ft.query(n);
      int part = ft.query(ed[v]) - ft.query(st[v] - 1);
      ans.push_back(abs(all - 2 * part));
    }
  }

  for (int x : ans) {
    cout << x << '\n';
  }
}
