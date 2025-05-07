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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> h(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  vector<vector<pair<int, int>>> que(n + 1);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    que[l].push_back({r, i});
  }
  stack<int> st;
  Fenwick<int> ft(n + 5);
  vector<int> ans(q);
  for (int i = n; i >= 1; i--) {
    for (auto [r, id] : que[i]) {
      ans[id] = ft.query(n) - ft.query(r);
    }
    while (st.size() && h[st.top()] < h[i]) {
      ft.update(st.top(), -1);
      st.pop();
    }
    st.push(i);
    ft.update(i, 1);
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
}


