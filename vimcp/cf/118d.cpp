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

const int MOD = (int) 1e8;
int n1, n2, k1, k2;
map<vector<int>, int> dp[202];

int memo(int i, bool state, int c, int rem1, int rem2) {
  if(i == n1 + n2 && rem1 == 0 && rem2 == 0) {
    //dbg(i, curr);
    return 1;
  }
  if(dp[i].count({state, c, rem1, rem2})) {
    return dp[i][{state, c, rem1, rem2}];
  }
  int ans = 0;
  if(!state) {
    if(rem1 > 0) {
      if(c < k1) {
        ans += memo(i + 1, false, c + 1, rem1 - 1, rem2);
        ans %= MOD;
      }
    }
    if(rem2 > 0) {
      ans += memo(i + 1, true, 1, rem1, rem2 - 1);
      ans %= MOD;
    }
  }
  else if(state) {
    if(rem2 > 0) {
      if(c < k2) {
        ans += memo(i + 1, true, c + 1, rem1, rem2 - 1);
        ans %= MOD;
      }
    }
    if(rem1 > 0) {
      ans += memo(i + 1, false, 1, rem1 - 1, rem2);
      ans %= MOD;
    }
  }
  return (dp[i][{state, c, rem1, rem2}] = ans);
}


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n1 >> n2 >> k1 >> k2;
  int ans = 0;
  cout << memo(0, false, 0, n1, n2);
}

