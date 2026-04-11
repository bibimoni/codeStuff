/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int r = 0;
  for (int i = 1; i <= l; i++) {
    r += a[i];
  }

  r = m - (r % m);

  auto get_w = [&](int id, int inc) -> int {
    int need = 0;
    int toCmp = (a[id] + inc) % m;
    for (int i = id; i <= n; i += l) {
      need += (toCmp - a[i] + m) % m;
    }
    return need;
  };

  const int inf = 1e9;
  vector<vector<int>> dp(n + 1, vector<int>(r + 1, inf));
  dp[0][0] = 0;
  for (int i = 1; i <= l; i++) {
    for (int rem = 0; rem <= r; rem++) {
      for (int ar = 0; ar <= r; ar++) {
        dp[i][(rem + ar) % m] =
            min(dp[i][(rem + ar) % m], dp[i - 1][rem] + get_w(i, ar));
      }
    }
  }

  cout << dp[l][r];
}
