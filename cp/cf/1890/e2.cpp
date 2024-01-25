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
#define all(x)         x.begin(), x.end()

struct BIT {
  const int N = (int) 2e5 + 5;
  int ft[200005];
  void init() {
    for(int i = 0; i < N; i++) {
      ft[i] = 0;
    }
  }
  void update(int id, int val) {
    while(id < N) {
      ft[id] = max(ft[id], val);
      id += (id & -id);
    }
  }
  int get(int id) {
    int ans = 0;
    while(id > 0) {
      ans = max(ans, ft[id]);
      id -= (id & -id);
    }
    return ans;
  }
} fenwick[13];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> q;
    vector<vector<int>> pos(n + 1);
    int dp[n + 10][k + 10];
    memset(dp, 0, sizeof dp);
    int res = 0;
    for(int i = 0; i <= k; i++) fenwick[i].init();
    for(int i = 0, l, r; i < m; i++) {
      cin >> l >> r;
      q.push_back({l, r});
      pos[l].push_back(i);
      if(r + 1 <= n) pos[r + 1].push_back(~i);
    }
    set<int> s;
    for(int i = 1; i <= n; i++) {
      for(auto j : pos[i]) {
        if(j >= 0) {
          s.insert(j);
        }
        if(j < 0) {
          s.erase(~j);
        }
      }
      if(s.size() == 0) {
        fenwick[0].update(i, dp[i - 1][0] + 1);
      }
      else if(s.size() <= k) {
        int dt = (int) s.size();
        for(int j = dt; j <= k; j++) {
          dp[i][j] = max(dp[i][j], fenwick[j - dt].get(i - 1));
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= k; j++) {
        ans = max(ans, dp[i][j]);
      }
    }
    cout << ans << '\n';
  }
}



