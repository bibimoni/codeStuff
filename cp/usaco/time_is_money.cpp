/**
 * File              : time_is_money.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 31.07.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e4 + 5

int nxt() {int n; cin >> n; return n;}
vector<vector<int>> dp(2, vector<int>(MAXN, -1)); 

signed main() {
  TLE;
  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);
  int n, m, c; cin >> n >> m >> c;
  int earn[n + 1];
  for(int i = 1; i <= n; i++) {
     cin >> earn[i];
  }
  vector<pair<int, int>> edges;
  for(int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    edges.push_back({a, b});
  }
  int ans = 0;
  dp[0][1] = 0;
  for(int i = 1; i < MAXN; i++) {
    for(auto e : edges) {
      int f = e.first, t = e.second;
      if(dp[(i - 1) % 2][f] >= 0) {
        dp[i % 2][t] = max(dp[i % 2][t], dp[(i - 1) % 2][f] + earn[t]);
      }
    }
    ans = max(ans, dp[i % 2][1] - c * i * i);
  }
  cout << ans;
}

