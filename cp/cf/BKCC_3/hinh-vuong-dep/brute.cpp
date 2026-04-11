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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

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

template <class T> class Fenwick2D {
  vector<Fenwick<T>> ft;
  int n, m;

public:
  Fenwick2D() {}

  Fenwick2D(int _n, int _m) : n(_n), m(_m) {
    ft.assign(n + 5, Fenwick<T>(m + 5));
  }

  void update(int r, int c, T del) {
    for (; r <= n; r += (r & -r)) {
      ft[r].update(c, del);
    }
  }

  T query(int r, int c) {
    T q = 0;
    for (; r > 0; r -= (r & -r)) {
      q += ft[r].query(c);
    }
    return q;
  }

  T query(int r1, int c1, int r2, int c2) {
    assert(r1 <= r2 && c1 <= c2);
    return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) +
           query(r1 - 1, c1 - 1);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;

    vector<int> hx(n + 1);
    vector<int> hy(n + 1);
    for (int i = 1; i <= n; i++) {
      hx[i] = rng();
      hy[i] = rng();
    }

    vector<vector<int>> ax(n + 1, vector<int>(n + 1));
    vector<vector<int>> ay(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      ax[x][y] = hx[x];
      ay[x][y] = hy[y];
    }

    for (int i = 1; i <= n; i++) {
      hx[i] += hx[i - 1];
      hy[i] += hy[i - 1];
    }

    Fenwick2D<int> ftx(n + 1, n + 1);
    Fenwick2D<int> fty(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ftx.update(i, j, ax[i][j]);
        fty.update(i, j, ay[i][j]);
      }
    }

    int q;
    cin >> q;
    while (q--) {
      int k, x, y;
      cin >> k >> x >> y;
      int sx = ftx.query(x, y, x + k - 1, y + k - 1);
      int sy = fty.query(x, y, x + k - 1, y + k - 1);
      cout << (sx == hx[x + k - 1] - hx[x - 1] &&
                       sy == hy[y + k - 1] - hy[y - 1]
                   ? "Yes\n"
                   : "No\n");
    }
  }
}
