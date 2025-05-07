class Fenwick2D {
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
