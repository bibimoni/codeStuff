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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int mx = *max_element(a.begin() + 1, a.end()) + 1;
  vector<vector<int>> pos(mx + 1);
  vector<vector<int>> level(n + 1);
  Fenwick<int> ft(n + 1);
  vector<int> xs;
  for (int i = 1; i <= n; i++) {
    level[i].push_back(1);
    pos[a[i]].push_back(i);
    xs.push_back(i);
    ft.update(i, 1);
  }
  for (int lvl = 1; lvl <= n; lvl++) {
    vector<int> nxs;
    for (int x : xs) {
      int l = level[x].back(), r = n, ret = n + 1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (ft.query(m) - ft.query(level[x].back()) >= x) {
          ret = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      if (ret <= n) {
        nxs.push_back(x);
        level[x].push_back(ret);
      }
    }
    swap(nxs, xs);
    if (lvl > mx) {
      continue;
    }
    for (int i : pos[lvl]) {
      ft.update(i, -1);
    }
  }
  dbg(level);
  while (q--) {
    int i, x;
    cin >> i >> x;
    if (level[x].size() <= a[i] || level[x][a[i]] > i) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

