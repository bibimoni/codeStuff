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

const int LG = 19;

template<class T>
struct RMQ {
  vector<vector<T>> st;
  int n;
  void build (const vector<T> &a) {
    n = a.size() - 1;
    st = vector<vector<T>>(LG + 1, vector<T>(n + 5));
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T query(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  sort(a.begin() + 1, a.end());
  vector<int> pb(n + 1), diff(n + 1);
  for (int i = 1; i <= n; i++) {
    pb[i] = pb[i - 1] + a[i].second;
    if (i > 1) {
      diff[i] = a[i].first - a[i - 1].first;
    }
  }
  RMQ<int> rmq;
  rmq.build(diff);
  const int INF = 1e9;
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    if (a[i].second >= c) {
      ans = 0;
      break;
    }
    int lo = 1, hi = i - 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (pb[i] - pb[mid - 1] >= c) {
        lo = mid + 1;
        ans = min(ans, rmq.query(mid + 1, i));
      } else {
        hi = mid - 1;
      }
    }
  }
  cout << ans << '\n';
}


