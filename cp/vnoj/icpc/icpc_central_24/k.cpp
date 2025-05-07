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

const vector<int> dir{-1, 0, 1, 0, -1};
const int INF = int(1e18);

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n));
  int k = 0;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      string x;
      cin >> x;
      g[i][j] = (x == "*" ? 0 : stoi(x));
      if (x == "*") {
        k += 1;
        a.push_back({i, j});
      }
    }
  }
  if (k == 0) {
    cout << "0\n";
    return 0;
  }
  vector<vector<vector<int>>> d(k, vector<vector<int>>(n, vector<int>(n, INF)));
  int i1 = 0;
  for (auto [x, y] : a) {
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {x, y}});
    d[i1][x][y] = 0;    
    while (st.size()) {
      auto [w1, u] = *st.begin();
      auto [ux, uy] = u;
      st.erase(st.begin());
      if (d[i1][ux][uy] != w1) {
        continue;
      }
      for (int i = 0; i < 4; i++) {
        int vx = ux + dir[i];
        int vy = uy + dir[i + 1];
        if (vx < 0 || vy < 0 || (vx >= n) || (vy >= n)) {
          continue;
        }
        if (d[i1][vx][vy] > d[i1][ux][uy] + g[vx][vy]) {
          d[i1][vx][vy] = d[i1][ux][uy] + g[vx][vy];
          st.insert({d[i1][vx][vy], {vx, vy}});
        }
      }
    }
    i1 += 1;
  }
  auto calc = [&] (int sz, int offset, vector<vector<vector<int>>> &m_cost) -> void {
    m_cost = vector<vector<vector<int>>>(int(1) << sz, vector<vector<int>>(n, vector<int>(n, INF)));
    for (int mask = 0; mask < (int(1) << sz); mask++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (g[i][j] == 0) {
            continue;
          }
          int cur = 0;
          bool valid_pos = true;
          for (int b = 0; b < sz; b++) {
            if ((mask >> b) & 1) {
              cur += d[b + offset][i][j];
            }
          }
          if (valid_pos) {
            m_cost[mask][i][j] = cur;
          }
        }
      }
    }
  };

  int fh = (k + 1) / 2, sh = k - fh;
  array<vector<vector<vector<int>>>, 2> cost;
  calc(fh, 0, cost[0]);
  calc(sh, fh, cost[1]);

  auto get_mask_cost = [&] (int mask, int r, int c) -> int {
    int fm = mask & ((int(1) << fh) - 1);
    int sm = mask >> fh;
    return cost[0][fm][r][c] + cost[1][sm][r][c];
  };

  auto get = [&] (int mask) -> int {
    int m_cost = INF;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        m_cost = min(m_cost, get_mask_cost(mask, i, j));
      }
    }
    return m_cost;
  };
  vector<int> m_cost(int(1) << k, INF);
  for (int mask = 0; mask < (int(1) << k); mask++) {
    m_cost[mask] = get(mask);    
  }
  vector<int> dp(int(1) << k, INF);
  for (int i = 0; i < k; i++) {
    dp[int(1) << i] = 0;
  }
  for (int mask = 0; mask < (int(1) << k); mask++) {
    for (int subset = mask; ; subset = (subset - 1) & mask) {
      dp[mask] = min(dp[mask], dp[subset] + dp[mask ^ subset] + m_cost[mask]);
      if (subset == 0) {
        break;
      }
    }
  }
  cout << dp[(int(1) << k) - 1];
}

