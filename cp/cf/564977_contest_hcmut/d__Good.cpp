// time-limit: 3000
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  bool is_sub3 = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      is_sub3 &= (a[i][j] <= 20);
    }
  }
  struct Q {
    int x_1, y_1, x_2, y_2;
    Q(int _x1, int _y1, int _x2, int _y2) {
      x_1 = _x1, x_2 = _x2, y_1 = _y1, y_2 = _y2;
    }
    Q() {}
  };
  int q;
  cin >> q;
  vector<Q> que(q);
  for (int i = 0; i < q; i++) {
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;

    que[i] = Q(x, y, x2, y2);
  }
  auto sub_1 = [&] () {
    for (auto Q : que) {
      set<int> st;
      for (int x = Q.x_1; x <= Q.x_2; x++) {
        for (int y = Q.y_1; y <= Q.y_2; y++) {
          st.insert(a[x][y]);
        }
      }
      cout << st.size() << '\n';
    }
  };
  auto sub_3 = [&] () {
    vector<Fenwick2D<int>> ft(21);
    for (int i = 1; i < 21; i++) {
      ft[i] = Fenwick2D<int>(n + 1, m + 1);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ft[a[i][j]].update(i, j, 1);
      }
    }
    for (auto Q : que) {
      int cnt = 0;
      for (int i = 1; i < 21; i++) {
        cnt += (ft[i].query(Q.x_1, Q.y_1, Q.x_2, Q.y_2) > 0);
        // dbg(Q.x_1, Q.x_2, Q.y_1, Q.y_2);
        // dbg(cnt, i);
      }
      cout << cnt << '\n';
    }
  };
  const int SUB1 = 200;
  if (is_sub3) {
    sub_3();
  } else 
  if (n <= SUB1 && m <= SUB1 && q <= SUB1) {
    sub_1();
  }
}


