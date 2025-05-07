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
  vector<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s.push_back(a[i]);
  }

  vector<vector<pair<int, int>>> que(n + 1);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    que[l].push_back({r, i});
  }

  vector<int> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  vector<int> ans(q);
  vector<int> contribute(n + 1, 0);
  deque<pair<int, int>> cur;
  Fenwick<int> ft(n + 1);
  for (int l = n; l >= 1; l--) {
    while (cur.size() && cur.front().first <= a[l]) {
      int idx = cur.front().second;
      ft.update(idx, -contribute[idx]);
      contribute[idx] = int(0);
      cur.pop_front();
    }
    cur.push_front({a[l], l});
    int after = (cur.size() == 1 ? n + 1 : cur[1].second); //second element
    contribute[l] = a[l] * (after - l) - sum[after - 1] + sum[l - 1];
    ft.update(l, contribute[l]);
    for (const auto &[r, id] : que[l]) {
      int ret = 0, lo = 0, hi = int(cur.size() - 1);
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (cur[mid].second <= r) {
          lo = mid + 1;
          ret = mid;
        } else {
          hi = mid - 1;
        }
      }
      int before_ret = ft.query(cur[ret].second - 1);
      int after_ret = (r - cur[ret].second + 1) * cur[ret].first - (sum[r] - sum[cur[ret].second - 1]);
      ans[id] = before_ret + after_ret;
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
}

