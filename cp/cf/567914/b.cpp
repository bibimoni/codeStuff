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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> p(n + 1);
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    if (i > 2 && p[i] != p[i - 1]) {
      ok = false;
    }
  }
  if (ok) {
    vector<int> trace(n + 1);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= min(k, n); i++) {
      trace[i] = -1;
      dp[i] = a[i];
    }
    for (int i = k + 1; i <= n; i++) {
      int id = i - k;
      for (int x = i - k; x >= max(int(0), i - 2 * k + 1); x--) {
        if (dp[id] < dp[x]) {
          id = x;
        }
      }
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(q + 1, 0));
  for (int i = 1; i <= min(k, n); i++) {
    for (int j = 0; j <= min(q, p[i]); j++) {
      dp[i][j] = a[i] * j;
    }
  }
  // Fenwick2D<int> ft(n + 1, q + 1);
  for (int i = k + 1; i <= n; i++) {
    for (int j = 0; j <= q; j++) {
      for (int x = i - k; x >= max(int(0), i - 2 * k + 1); x--) {
        dp[i][j] = dp[i - 1][j];
        for (int pi = 0; pi <= min(p[i], j); pi++) {
          // dbg(i, x, dp[x][j - pi], j, pi);
          dp[i][j] = max(dp[i][j], dp[x][j - pi] + pi * a[i]);
        }
      }
    }
  }
  cout << *max_element(dp[n].begin(), dp[n].end());
}

