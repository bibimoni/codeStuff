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

  Fenwick2D(int _n, int m) : n(_n) { ft.assign(n + 5, Fenwick<T>(m + 5)); }

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> cands;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    auto inBound = [&](int x, int y) -> bool {
      return x - k / 2 > 0 && x + k / 2 <= n && y - k / 2 > 0 && y + k / 2 <= m;
    };
    vector<int> meds;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        meds.push_back(a[i][j]);
        if (inBound(i, j)) {
          cands.push_back({i, j});
        }
      }
    }
    dbg(cands);

    sort(meds.begin(), meds.end());
    meds.erase(unique(meds.begin(), meds.end()), meds.end());
    auto id = [&](int x) -> int {
      return lower_bound(meds.begin(), meds.end(), x) - meds.begin() + 1;
    };

    int s = cands.size();
    int mx = meds.size();
    vector<vector<pair<int, int>>> ll(mx + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ll[id(a[i][j])].push_back({i, j});
      }
    }
    const int INF = 1e9;
    vector<int> lo(s, 1), hi(s, mx), ret(s, -1);
    int bound = (k * k + 1) / 2;
    while (true) {
      bool processing = false;
      vector<vector<int>> check(mx + 1);
      Fenwick2D<int> ft(n, m);
      for (int i = 0; i < s; i++) {
        if (lo[i] > hi[i]) {
          continue;
        }
        int mid = (lo[i] + hi[i]) / 2;
        check[mid].push_back(i);
        processing = true;
      }
      if (!processing) {
        break;
      }
      for (int med = 1; med <= mx; med++) {
        for (auto [x, y] : ll[med]) {
          ft.update(x, y, 1);
        }
        for (int i : check[med]) {
          auto [x, y] = cands[i];
          int x1 = x - k / 2, y1 = y - k / 2;
          int x2 = x + k / 2, y2 = y + k / 2;
          int cnt = ft.query(x2, y2) - ft.query(x1 - 1, y2) -
                    ft.query(x2, y1 - 1) + ft.query(x1 - 1, y1 - 1);
          if (cnt >= bound) {
            hi[i] = med - 1;
            ret[i] = med;
          } else {
            lo[i] = med + 1;
          }
        }
      }
    }
    dbg(lo, hi, ret);
    for (int i = 0; i < s; i++) {
      auto [x, y] = cands[i];
      assert(ret[i] != -1);
      a[x][y] = meds[ret[i] - 1];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << a[i][j] << " \n"[j == m];
      }
    }
  }
}
