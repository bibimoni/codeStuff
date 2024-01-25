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

const int INF = (int) 4e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, b; cin >> n >> m >> b;
  int rub[n + 1], monitor[n + 1];
  vector<vector<int>> pro(n + 1);
  for(int i = 1; i <= n; i++) {
    int sz;
    cin >> rub[i] >> monitor[i] >> sz;
    for(int j = 1; j <= sz; j++) {
      int x; cin >> x;
      pro[i].push_back(x);
    }
  }
  vector<int> p(n + 1, 0);
  iota(p.begin(), p.end(), 0);
  sort(p.begin() + 1, p.end(), [&] (int i, int j) {
    return monitor[i] < monitor[j];
  });
  vector<int> dp(1 << m, INF);
  dp[0] = 0;
  int subset[n + 1];
  for(int id = 1; id <= n; id++) {
    int curr = 0, i = p[id];
    for(auto j : pro[i]) {
      j--;
      curr |= (1 << j);
    }
    subset[i] = curr;
  }
  int ans = INF;
  for(int id = 1; id <= n; id++) {
    int i = p[id];
    for(int sub = 0; sub < (1 << m); sub++) {
      if(dp[sub] == INF) continue;
      //overflow counter     
      int newCost = dp[sub] + rub[i];
      if(dp[sub | subset[i]] > newCost) {
        dp[sub | subset[i]] = newCost;
      }
    }
    int curr = dp[(1 << m) - 1];
    curr += monitor[i] * b;
    if(curr < ans) {
      ans = curr;
    }
  }
  cout << (ans == INF ? -1 : ans);
}

