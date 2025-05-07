/**
 * Description: Matrices with binary exponentiation utility
 */

template <class T> struct matrix {
  vector<vector<T>> a;
  int n, m;

  matrix() {}

  matrix(int _n, int _m) : n(_n), m(_m) {
    a = vector<vector<T>>(n, vector<T>(m));
  }

  matrix(int _n, int _m, T val) : n(_n), m(_m) {
    a = vector<vector<T>>(n, vector<T>(m, val));
  }

  matrix(const vector<T> &oth) {
    a = vector<vector<T>>(sz(oth), vector<T>(1));
    n = sz(oth);
    m = 1;
    for (int i = 0; i < sz(oth); i++) {
      a[i][0] = oth[i];
    }
  }

  matrix(const vector<vector<T>> &oth) {
    a = oth;
    n = sz(a);
    m = sz(a[0]);
  }

  matrix operator*(const matrix &oth) const {
    assert(m == oth.n);
    matrix r(n, oth.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < oth.m; j++) {
        for (int k = 0; k < m; k++) {
          r.a[i][j] += a[i][k] * oth.a[k][j];
        }
      }
    }
    return r;
  }

  matrix &operator*=(const matrix &oth) {
    *this = (*this) * oth;
    return *this;
  }

  template <class U> friend matrix power(const matrix &a, const U &b) {
    assert(b >= 0);
    assert(a.n == a.m);
    matrix x = a;
    matrix res(a.n, a.m);
    for (int i = 0; i < a.n; i++)
      res.a[i][i] = 1;
    U p = b;
    while (p > 0) {
      if (p & 1)
        res *= x;
      x *= x;
      p >>= 1;
    }
    return res;
  }

  friend string to_string(matrix M) {
    int mx = 0;
    for (int i = 0; i < M.n; i++) {
      for (int j = 0; j < M.m; j++) {
        mx = max(mx, sz(to_string(M.a[i][j])));
      }
    }
    string res = "";
    for (int i = 0; i < M.n; i++) {
      res += "\n[";
      for (int j = 0; j < M.m; j++) {
        if (j) {
          res += ", ";
        }
        string cur = to_string(M.a[i][j]);
        res += string(mx - sz(cur), ' ') + cur;
      }
      res += "]";
    }
    return res;
  }
};
