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
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
  }
  T query(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  auto ok = [&] (int w) -> bool {
    const int inf = int(1e9);
    vector<vector<int>> dp(n + 1, vector<int>(min(n + 1, p + 1), inf));
    int small = 1, large = 1;
    for (int j = 0; j <= min(n, p); j++) {
      dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      while (small <= i && a[i] - a[small] + 1 > w) {
        small += 1;
      }
      while (large <= i && a[i] - a[large] + 1 > 2 * w) {
        large += 1;
      }
      for (int j = 0; j <= min(n, p); j++) {
        if (j == 0) {
          dp[i][j] = min(dp[i][j], dp[large - 1][j] + 1);
        } else {
          dp[i][j] = min({dp[i][j], dp[small - 1][j - 1], dp[large - 1][j] + 1});
        }
      }
    }
    bool ok = false;
    for (int j = 0; j <= min(n, p); j++) {
      ok |= dp[n][j] <= q;
    }
    return ok;
  };

  int l = 0, r = int(1e9), ans = 1e9;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (ok(m)) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  cout << ans << '\n';
}

