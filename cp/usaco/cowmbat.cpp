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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("cowmbat.in", "r", stdin);
  freopen("cowmbat.out", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(m + 1, vector<int>(m + 1));
  string s;
  cin >> s;
  s = " " + s;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int k = 1; k <= m; k++) {
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  const int INF = 1e18;
  vector<vector<int>> change(n + 1, vector<int>(m + 1, 0));
  for (int c = 1; c <= m; c++) {
    for (int i = 1; i <= n; i++) {
      change[i][c] = change[i - 1][c] + a[s[i] - 'a' + 1][c];
    }
  }
  auto calc = [&] (int l, int r, int c) -> int {
    return change[r][c] - change[l - 1][c];
  };
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
  vector<int> mn(n + 1, INF);

  mn[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = dp[i - 1][j] + a[s[i] - 'a' + 1][j];
      if (i - k >= 0) {
        dp[i][j] = min(dp[i][j], mn[i - k] + calc(i - k + 1, i, j));
      }
      mn[i] = min(mn[i], dp[i][j]);
    }
  }
  cout << mn[n];
}

