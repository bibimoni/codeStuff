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

const int N = (int) 1e5 + 5;
int dp[N][3][3] = {};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("CAU3.INP", "r", stdin);
  freopen("CAU3.OUT", "w", stdout);
  string s; 
  cin >> s;
  int n = s.size();
  s = " " + s; 
  for(int i = 1; i <= n; i++) 
    for(int j = 0; j < 3; j++) 
      for(int k = 0; k < 3; k++)
        dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  //dp[i][state][j] the num of the first i number has the remainder j 
  //state = 0 take -> 0
  //state = 1 currently not taking -> 0 1
  //state = 2 already not taken -> 1 2 (be active when u not take)
  for(int i = 1; i <= n; i++) {
    int curr = (s[i] - '0') % 3;
    for(int j = 0; j < 3; j++) {
      //state = 0
      dp[i][0][(j + curr) % 3] += dp[i - 1][0][j];
      //state = 1
      dp[i][1][j] += dp[i - 1][0][j];
      dp[i][1][j] += dp[i - 1][1][j];
      //state = 2
      dp[i][2][(j + curr) % 3] += dp[i - 1][2][j];
      dp[i][2][(j + curr) % 3] += dp[i - 1][1][j];
    }
  }
  cout << dp[n][0][0] + dp[n][1][0] + dp[n][2][0] - 1;
} 


