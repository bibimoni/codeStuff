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
  int n, q;
  cin >> n >> q;
  vector<string> a(n + 1);
  Fenwick2D<int> ft(n + 1, n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = " " + a[i];
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == '*') {
        ft.update(i, j, 1);
      }
    }
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int r, c;
      cin >> r >> c;
      if (a[r][c] == '.') {
        ft.update(r, c, 1); 
        a[r][c] = '*';
      } else {
        ft.update(r, c, -1);
        a[r][c] = '.';
      }
    } else if (type == 2) {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      cout << ft.query(r1, c1, r2, c2) << '\n';
    }
  }
}
