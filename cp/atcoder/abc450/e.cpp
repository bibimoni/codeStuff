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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string x, y;
  cin >> x >> y;
  int nx = (int)x.size(), ny = (int)y.size();
  x = " " + x;
  y = " " + y;

  int q;
  cin >> q;
  vector<array<int, 26>> px(nx + 1);
  for (int i = 1; i <= nx; i++) {
    for (int c = 0; c < 26; c++) {
      px[i][c] = px[i - 1][c] + int(c == x[i] - 'a');
    }
  }
  vector<vector<int>> py(ny + 1, vector<int>(26));
  for (int i = 1; i <= ny; i++) {
    for (int c = 0; c < 26; c++) {
      py[i][c] = py[i - 1][c] + int(c == y[i] - 'a');
    }
  }

  vector<int64_t> len{0, nx, ny};
  while (len.back() < int64_t(1e18)) {
    len.push_back(len[len.size() - 1] + len[len.size() - 2]);
  }

  vector<vector<int64_t>> cnt(len.size(), vector<int64_t>(26));
  for (int i = 1; i < (int)len.size(); i++) {
    for (int c = 0; c < 26; c++) {
      if (i == 1) {
        cnt[i][c] = px[nx][c];
      } else if (i == 2) {
        cnt[i][c] = py[ny][c];
      } else {
        cnt[i][c] = cnt[i - 1][c] + cnt[i - 2][c];
      }
    }
  }

  while (q--) {
    int64_t l, r;
    char c;
    cin >> l >> r >> c;
    int cc = c - 'a';
    auto dfs = [&](auto &&self, int n, int64_t k, int c) -> int64_t {
      if (k == 0) {
        return 0;
      }
      if (n == 1) {
        return px[k][c];
      }
      if (n == 2) {
        return py[k][c];
      }
      if (k <= len[n - 1]) {
        return self(self, n - 1, k, c);
      } else {
        return cnt[n - 1][c] + self(self, n - 2, k - len[n - 1], c);
      }
    };

    auto f = [&](int64_t idx, int c) -> int64_t {
      if (idx == 0) {
        return 0;
      }
      return dfs(dfs, int(len.size() - 1), idx, c);
    };

    cout << f(r, cc) - f(l - 1, cc) << '\n';
  }
}
