// time-limit: 3000
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
#define int            long long

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    vector<int> cost(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      vector<int> dp(m + 1, INF);
      dp[1] = 1, dp[m] = 1;
      deque<int> dq;
      dq.push_back(1);
      for(int j = 2; j < m; j++) {
        while(dq.size() && j - dq.front() - 1 > d) {
          dq.pop_front();
        }
        dp[j] = min(dp[j], dp[dq.front()] + a[i][j] + 1);
        while(dq.size() && dp[dq.back()] >= dp[j]) {
          dq.pop_back();
        }
        dq.push_back(j);
      }
      while(dq.size() && m - dq.front() - 1 > d) {
        dq.pop_front();
      }
      cost[i] = 1 + dp[dq.front()];
    }
    int ans = INF;
    for(int i = 1; i <= n; i++) {
      cost[i] += cost[i - 1];
    }
    for(int i = k; i <= n; i++) {
      ans = min(ans, cost[i] - cost[i - k]);
    }
    cout << ans << '\n';
  }
}


