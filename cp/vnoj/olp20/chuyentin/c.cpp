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
  int n, m;
  cin >> n >> m;
  bool has_zero = false;
  pair<int, int> zero_pos;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      has_zero |= a[i][j] == 0;
      if (a[i][j] == 0) {
        zero_pos = {i, j};
      }
    }
  }
  
  auto get_f = [&] (int num, int p) -> int {
    int ret = 0;
    while (num > 0 && num % p == 0) {
      num /= p;
      ret += 1;
    }
    return ret;
  };

  auto cmp = [&] (pair<int, int> i, pair<int, int> j) -> bool {
    return min(i.second, i.first) < min(j.first, j.second);
  };

  auto add = [&] (pair<int, int> i, pair<int, int> j) -> pair<int, int> {
    return pair<int, int>(i.first + j.first, i.second + j.second);
  };

  vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, {0, 0}));
  vector<vector<pair<int, int>>> trace(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        continue;
      }
      int c2 = get_f(a[i][j], 2);
      int c5 = get_f(a[i][j], 5);
      dp[i][j] = {c2, c5};
      if (i == 1 && j == 1) {
        continue;
      }
      if (i == 1 || a[i - 1][j] == 0) {
        dp[i][j] = add(dp[i][j], dp[i][j - 1]);
        trace[i][j] = {i, j - 1};
      } else if (j == 1 || a[i][j - 1] == 0) {
        dp[i][j] = add(dp[i][j], dp[i - 1][j]);
        trace[i][j] = {i - 1, j};
      } else {
        if (cmp(dp[i - 1][j], dp[i][j - 1])) {
          dp[i][j] = add(dp[i][j], dp[i - 1][j]);
          trace[i][j] = {i - 1, j};
        } else {
          dp[i][j] = add(dp[i][j], dp[i][j - 1]);
          trace[i][j] = {i, j - 1};
        }
      }
    }
  }
  int ret = min(dp[n][m].first, dp[n][m].second);
  if (has_zero && ret > 0) {
    cout << "1\n" << string(zero_pos.first - 1, 'D') 
      << string(zero_pos.second - 1, 'L')
      << string(n - zero_pos.first, 'D')
      << string(m - zero_pos.second, 'L');
    return 0;
  }
  cout << ret << '\n';
  string ans = "";
  pair<int, int> cur{n, m};
  while (trace[cur.first][cur.second] != pair<int, int>{-1, -1}) {
    pair<int, int> nxt = trace[cur.first][cur.second];
    if (cur.first - nxt.first == 1) {
      ans += "D";
    } else {
      ans += "L";
    }
    cur = nxt;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
} 

