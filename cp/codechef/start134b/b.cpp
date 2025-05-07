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

int dp[20][3][100];

int calc(string &s, int i, int ok, int sum) {
  if(i == s.size()) {
    return sum;
  }
  if(dp[i][ok][sum] != -1) {
    return dp[i][ok][sum];
  }
  int ans = 0;
  int limit = (ok ? 9 : s[i] - '0');
  for(int j = 0; j <= limit; j++) {
    int tmp = sum + j;
    if(tmp >= 10) {
      tmp = (tmp / 10) + (sum + j) % 10;
    }
    ans += calc(s, i + 1, ok || (j < s[i] - '0'), tmp);
  }
  dp[i][ok][sum] = ans;
  return ans;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    string in = to_string(n);
    cout << calc(in, 0, 0, 0) << '\n';
  }
}

