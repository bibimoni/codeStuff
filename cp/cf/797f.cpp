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
#define int long long
const int N = (int) 5e3 + 5, LG = 17, INF = (int) 1e18;

struct Hole {
  int p, c;
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int x[n + 1];
  Hole holes[m + 1];
  for(int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  int places = 0;
  for(int i = 1; i <= m; i++) {
    cin >> holes[i].p >> holes[i].c;
    places += holes[i].c;
  }
  if(places < n) {
    cout << "-1\n";
    return 0;
  }
  sort(x + 1, x + 1 + n);
  sort(holes + 1, holes + m + 1, [&] (Hole a, Hole b) {
    return a.p < b.p;
  });
  vector<vector<int>> dist(m + 1, vector<int>(n + 1, 0));
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      dist[i][j] = dist[i][j - 1] + abs(holes[i].p - x[j]);
    }
  }
  auto get = [&] (int id, int l, int r) -> int {
    return dist[id][r] - (l == 0 ? 0 : dist[id][l - 1]);
  };
  vector<vector<int>> dp(2, vector<int>(n + 1, INF));
  int prev = 0;
  for(int i = 1; i <= m; i++) {
    deque<int> dq;
    dp[(i - 1) % 2][0] = 0;
    dq.push_back(0);
    for(int j = 1; j <= n; j++) {
      while(dq.size() && j <= n && (dq.back() > 0 ? dp[(i - 1) % 2][dq.back() - 1] : 0) + get(i, dq.back(), j) >= dp[(i - 1) % 2][j - 1] + get(i, j, j)) {
        dq.pop_back();
      }
      while(dq.size() && j - dq.front() + 1 > holes[i].c) {
        dq.pop_front();
      }
      dq.push_back(j);
      if(dq.size()) {
        int k = dq.front();
        int prev = (k == 0 ? 0 : dp[(i - 1) % 2][k - 1]);
        dp[i % 2][j] = min(dp[(i - 1) % 2][j], prev + get(i, k, j));
      }
      else {
        dp[i % 2][j] = min(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1] + abs(holes[i].p - x[j]));
      }
    }
  } 
  cout << dp[m % 2][n];
}

