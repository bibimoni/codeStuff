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
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> h(n);  
  vector<int> s;
  for(int i = 0; i < n; i++) {
    cin >> h[i];
    s.push_back(h[i]);
  }
  vector<int> x(q);
  for(int i = 0; i < q; i++) {
    cin >> x[i];
    s.push_back(x[i]); 
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  auto get = [&] (int x) -> int {
    return lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
  };
  fenwick<int> ft(n + q + 100);
  for(int i = 0; i < n; i++) {
    ft.update(get(h[i]), 1);
  }
  for(int i = 0; i < q; i++) {
    ft.update(get(x[i]), 1);
    cout << ft.query(get(x[i])) << '\n';
  }
} 


