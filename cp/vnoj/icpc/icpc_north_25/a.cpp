/**
 * Author: distiled
 */
#include <algorithm>
#include<bits/stdc++.h>
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
  int p, q, r;
  cin >> p >> q >> r;
  vector<string> rows(q * p + 1);
  for (int i = 1; i <= p * q; i++) {
    cin >> rows[i]; 
    rows[i] = " " + rows[i];
  }
  vector a(p + 1, vector<vector<int>>(q + 1, vector<int>(r + 1)));
  for (int i = 1; i <= p; i++)
    for (int j = 1; j <= q; j++) 
      for (int k = 1; k <= r; k++) {
        a[i][j][k] = rows[(j * p + i - p)][k] == 'N' ? 1 : 0;
      }
  
  int ans = 0;
  auto go = [&](function<array<int, 3>(int, int, int)> g, array<int, 3> nsz) -> void {
    int np = nsz[0], nq = nsz[1], nr = nsz[2];
    vector b(np + 1, vector<vector<int>>(nq + 1, vector<int>(nr + 1)));
    for (int i = 1; i <= p; i++) {
      for (int j = 1; j <= q; j++) {
        for (int k = 1; k <= r; k++) {
          auto nc = g(i, j, k);
          b[nc[0]][nc[1]][nc[2]] = a[i][j][k];
        }
      }
    }

    vector dp(np + 1, vector<vector<int>>(nq + 1, vector<int>(nr + 1)));
    for (int i = 1; i <= np; i++) {
      for (int j = 1; j <= nq; j++) {
        for (int k = 1; k <= nr; k++) {
          if (!b[i][j][k]) {
            dp[i][j][k] = 0;
            continue;
          }

          dp[i][j][k] = min({dp[i - 1][j][k],dp[i][j - 1][k],dp[i - 1][j - 1][k]}) + 1;
        }
      }
    }

    for (int i = 1; i <= np; i++) {
      for (int j = 1; j <= nq; j++) {
        auto calc = [&](vector<int> &c) -> vector<int> {
          deque<int> dq;
          vector<int> ret(nr + 1);
          for (int k = 1; k <= nr; k++) {
            while (dq.size() && c[dq.back()] >= c[k]) {
              dq.pop_back();
            }  

            if (dq.size())
              ret[k] = (k - dq.back()) * c[k];
            else 
              ret[k] = c[k] * k;
            dq.push_back(k);
          }
          return ret;
        };
        auto &d = dp[i][j];
        auto v1 = calc(d);
        auto d2 = dp[i][j];
        reverse(d2.begin() + 1, d2.end());
        auto v2 = calc(d2);
        reverse(v2.begin() + 1, v2.end());
        for (int k = 1; k <= nr; k++) {
          ans = max(ans, v1[k] + v2[k] - d[k]);
        }
      }
    }
  };

  auto f = [&](int x, int y, int z) -> array<int, 3> {
    return {x, y, z};
  };

  auto f1 = [&](int x, int y, int z) -> array<int, 3> {
    return {x, z, y};
  };

  auto f2 = [&](int x, int y, int z) -> array<int, 3> {
    return {y, z, x};
  };

  go(f, f(p, q,r));
  go(f1, f1(p, q,r));
  go(f2, f2(p, q,r));

  cout << 4 * ans;
}
