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

#define int            long long

template <class T>
class fenwick {
  vector<T> a;
  int n;

public:
  fenwick() {}

  fenwick(int n_) : n(n_) {
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
  T range(int l, int r) {
    return query(r) - query(l - 1);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q; cin >> n >> q;
  fenwick<int> ft1(n), ft2(n);
  vector<int> rows(n + 1, 0), cols(n + 1, 0);
  auto checkRange = [&] (int l, int r, bool row) {
    int cnt;
    if(row) {
      cnt = ft1.range(l, r);
    }
    else {
      cnt = ft2.range(l, r);
    }
    return cnt == r - l + 1;
  };
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int x, y; cin >> x >> y;
      rows[x]++;
      cols[y]++;
      if(rows[x] == 1) ft1.update(x, 1);
      if(cols[y] == 1) ft2.update(y, 1);
    }
    else if(t == 2) {
      int x, y; cin >> x >> y;
      rows[x]--;
      cols[y]--;
      if(!rows[x]) ft1.update(x, -1);
      if(!cols[y]) ft2.update(y, -1);
    }
    else {
      int x, y, x2, y2; cin >> x >> y >> x2 >> y2;
      if(checkRange(x, x2, true) || checkRange(y, y2, false)) {
        cout << "Yes\n";
      }
      else {
        cout << "No\n";
      }
    }
  }
}

