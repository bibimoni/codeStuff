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
const int INF = (int) 1e18, N = (int) 2e4 + 5;
int dp[N][15][15];
int n, l, r, a[N];  
int memo(int i, int dist1, int dist2) {
  if(i == n + 1) return 0;
  if(dist1 > r && dist2 > r) return 0;
  dist1 = min(dist1, r + 1);
  dist2 = min(dist2, r + 1);
  if(dp[i][dist1][dist2] != -INF) return dp[i][dist1][dist2];
  int res = -INF;
  res = max(res, memo(i + 1, dist1 + (dist1 != 0), dist2 + (dist2 != 0)));
  if(!dist1 || (dist1 >= l && dist1 <= r)) {
    res = max(res, a[i] + memo(i + 1, 1, dist2 + (dist2 != 0)));
  }
  if(!dist2 || (dist2 >= l && dist2 <= r)) {
    res = max(res, -a[i] + memo(i + 1, dist1 + (dist1 != 0), 1));
  }
  return (dp[i][dist1][dist2] = res);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> l >> r; 
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= r + 1; j++)
      for(int k = 0; k <= r + 1; k++)
        dp[i][j][k] = -INF;
  cout << memo(1, 0, 0);
}

