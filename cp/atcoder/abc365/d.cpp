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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  map<char, int> mp;
  mp['R'] = 0;
  mp['P'] = 1;
  mp['S'] = 2;
  map<char, char> d;
  d['R'] = 'P';
  d['P'] = 'S';
  d['S'] = 'R';
  vector<int> c = {'R', 'P', 'S'};
  map<char, char> lost;
  lost['R'] = 'S';
  lost['S'] = 'P';
  lost['P'] = 'R';
  vector<array<int, 3>> dp(n + 1, {{0, 0, 0}});
  dp[1][mp[d[s[1]]]] = 1;
  const int INF = int(1e18);
  for (int i = 1; i <= n; i++) {
    int l = mp[lost[s[i]]];
    dp[i][l] = -INF;
  }
  for (int i = 2; i <= n; i++) {
    int win = mp[d[s[i]]];
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k || dp[i][j] == -INF || dp[i - 1][k] == -INF) {
          continue;
        }
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j == win));
      }
    }
  }
  cout << *max_element(dp[n].begin(), dp[n].end());
}


