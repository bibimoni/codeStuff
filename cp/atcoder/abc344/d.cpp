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
  string t;
  cin >> t;
  int m = t.size();
  t = " " + t;
  int n;
  cin >> n;
  
  const int INF = numeric_limits<int>::max();
  vector<vector<string>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++) {
      string s;
      cin >> s;
      a[i].push_back(s);
    }
  }
  vector<int> dp(m + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    vector<int> ndp(m + 1, INF);
    ndp[0] = 0;
    for (int j = 0; j < (int)a[i].size(); j++) {
      for (int st = 1; st <= m; st++) {
        ndp[st] = min(ndp[st], dp[st]);
        if (st - (int)a[i][j].size() >= 0 
          && t.substr(st - a[i][j].size() + 1, a[i][j].size()) == a[i][j]
          && dp[st - a[i][j].size()] != INF) {
          ndp[st] = min(ndp[st], dp[st - a[i][j].size()] + 1);
        }
      }
    }
    swap(ndp, dp);
  }
  cout << (dp[m] == INF ? -1 : dp[m]);
}

