/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

template <class T>
class Fenwick {
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
      a[r] += del; //check update rule
    }
  }
};

template <class T>
class Fenwick2D {
  vector<Fenwick<T>> ft;
  int n, m;
public:

  Fenwick2D() {}

  Fenwick2D(int _n, int m) : n(_n) {
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
    return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 3>> f_list; 
  vector<int> a(n + 1);
  Fenwick2D<int> f(n + 1, n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j <= i; j++) {
      f.update(j, i, abs(a[i] - a[j]));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      f_list.push_back({i, j, f.query(j, j, i, i)});
    }
  }
  sort(f_list.begin(), f_list.end(), [&] (array<int, 3> &i, array<int, 3> &j) {
    return i[2] > j[2];
  });
  int q;
  cin >> q;
  vector<array<int, 4>> que(q);
  for (int i = 0; i < q; i++) {
    cin >> que[i][0] >> que[i][1] >> que[i][2];
    que[i][3] = i;
  }
  sort(que.begin(), que.end(), [&] (array<int, 4> &i, array<int, 4> &j) {
    return i[2] < j[2];
  });
  Fenwick2D<int> ft(n + 1, n + 1);
  vector<int> ans(q);
  for (auto p : que) {
    int x = p[0], y = p[1], k = p[2], id = p[3];
    while (f_list.size() && f_list.back()[2] <= k) {
      auto [i, j, val] = f_list.back();
      f_list.pop_back();
      ft.update(i, j, 1);
    }
    ans[id] = ft.query(x, x, y, y);    
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}

