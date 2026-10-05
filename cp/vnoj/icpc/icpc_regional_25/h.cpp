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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].first >> p[i].second;
    }
    
    auto dist = [&](pair<int, int> i, pair<int, int> j) -> double {
      double x = i.first - j.first;
      double y = i.second - j.second;
      return sqrt(x * x + y * y);
    };

    const double inf = 1e9;
    vector<vector<array<double, 2>>> dp(n, vector<array<double, 2>>(n, {{inf, inf}}));
    for (int i = 0; i < n; i++) {
      dp[i][i] = {0, 0};
    }
    
    struct State {
      int l, r, t;
      int get() {
        if (t == 0) {
          return l;
        }
        return r;
      }
    };
    vector<vector<array<State,2>>> trace(n, vector<array<State,2>>(n));
    for (int len = 1; len < n; len++) {
      for (int i = 0; i < n; i++) {
        int ti = (i - 1 + n) % n;
        int tj = (i + len) % n;
        int j = (i + len - 1) % n;

        array<double, 3> cands = {
          dp[ti][j][0],
          dp[i][j][0] + dist(p[ti], p[i]),
          dp[i][j][1] + dist(p[ti], p[j])
        };
        int idx = int(min_element(cands.begin(), cands.end()) - cands.begin());
        dp[ti][j][0] = cands[idx];
        if (idx == 1) {
          trace[ti][j][0] = {i, j, 0};
        } else if (idx == 2) {
          trace[ti][j][0] = {i, j, 1};
        }

        cands = {
          dp[i][tj][1],
          dp[i][j][0] + dist(p[i], p[tj]),
          dp[i][j][1] + dist(p[j], p[tj])
        };
        idx = int(min_element(cands.begin(), cands.end()) - cands.begin());
        dp[i][tj][1] = cands[idx];
        if (idx == 1) {
          trace[i][tj][1] = {i, j, 0};
        } else if (idx == 2) {
          trace[i][tj][1] = {i, j, 1};
        }
      }
    }

    double ans = inf;
    State state = {0, 0, 0};
    for (int i = 0; i < n; i++) {
      int j = (i + n - 1) % n;
      if (ans > dp[i][j][0]) {
        ans = dp[i][j][0];
        state = {i, j, 0};
      } else if (ans > dp[i][j][1]) {
        ans = dp[i][j][1];
        state = {i, j, 1};
      }
    }

    assert(state.l != 0 || state.r != 0 || state.t != 0);

    vector<int> perm;
    for (int i = 0; i < n - 1; i++) {
       perm.push_back(state.get());      
       state = trace[state.l][state.r][state.t];
    }
    perm.push_back(state.get());

    assert((int)perm.size() == n);
    for (int i = 0; i < n; i++) {
      cout << perm[i] + 1 << " \n"[i == n - 1];
    }
  }
}
