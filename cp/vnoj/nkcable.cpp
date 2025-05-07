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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

const int INF = (int) 1e9, N = (int) 25111;
int d[N]; vector<array<int, 2>> dp(N, array<int, 2>{{INF, INF}});
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  for(int i = 2; i <= n; i++) cin >> d[i];
  dp[1][0] = dp[1][1] = 0
  dp[2][1] = dp[2][0] = d[2];
  for(int i = 3; i <= n; i++) {
    dp[i][0] = dp[i - 1][1]; 
    dp[i + 1][0] = dp[i][0] + d[i];
    dp[i][1] = min({dp[i - 1][1] + d[i], dp[i - 1][0] + d[i]});
  }
  cout << min(dp[n][0] + d[n], dp[n][1]);
}




