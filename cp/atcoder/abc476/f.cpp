/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#define table(x...)
#endif
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int nn = 2 * n;
  vector pre(nn + 1, vector(nn + 1, int(0)));
  vector<vector<pair<int, int>>> group(2 * n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      group[i + j].push_back({i, j});
    }
  }

  map<pair<int, int>, pair<int, int>> mp;
  for (int sum = n + 1, st = 1; sum >= 2; sum--, st++) {
    int j = st;
    reverse(group[sum].begin(), group[sum].end());
    for (auto [x, y] : group[sum]) {
      pre[sum - 1][j] = (a[x] * b[y]) % m; 
      mp[{x, y}] = {sum - 1, j};
      j += 2;
    }
  }

  for (int sum = n + 2, st = 2; sum <= 2 * n; sum++, st++) {
    int j = st;
    reverse(group[sum].begin(), group[sum].end());
    for (auto [x, y] : group[sum]) {
      pre[sum - 1][j] = (a[x] * b[y]) % m;
      mp[{x, y}] = {sum - 1, j};
      j += 2;
    }
  }

  auto pre2 = pre;
  auto pre1 = pre;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      auto [x, y] = mp[{i, j}];
      pre1[x][y] *= i;
      pre2[x][y] *= j; 
    }
  }

  for (int i = 1; i <= nn; i++) {
    for (int j = 1; j <= nn; j++) {
      pre1[i][j] += pre1[i - 1][j] + pre1[i][j - 1] - pre1[i - 1][j - 1]; 
      pre2[i][j] += pre2[i - 1][j] + pre2[i][j - 1] - pre2[i - 1][j - 1]; 
      pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]; 
    }
  }

  auto q = [&](int l, int r, int u, int d, vector<vector<int>> &p) -> int {
    return p[d][r] - p[d][l - 1] - p[u - 1][r] + p[u - 1][l - 1];
  };
  auto f = [&](int x, int y, int i, int j) -> int {
    int leftj = q(1, y - 1, 1, x, pre2); 
    int left = q(1, y - 1, 1, x, pre); 
    int rightj = q(y + 1, nn, x, nn, pre2); 
    int right = q(y + 1, nn, x, nn, pre); 
    int upi = q(y, nn, 1, x - 1, pre1);
    int up = q(y, nn, 1, x - 1, pre);
    int downi = q(1, y, x + 1, nn, pre1);
    int down = q(1, y, x + 1, nn, pre);
    return 
      left * j - leftj
      + rightj - right * j
      + up * i - upi
      + downi - down * i;
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      auto [x, y] = mp[{i, j}]; 
      ans ^= f(x, y, i, j) + (i - 1) * n + (j - 1);
    }
  }

  cout << ans << '\n';
}
