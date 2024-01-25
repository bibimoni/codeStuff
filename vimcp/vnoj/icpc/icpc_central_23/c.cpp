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
#define MULTI          int t;cin>>t;while(t--)
inline int nxt() { int n; cin >> n; return n; }

const int MOD = (int) 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  MULTI {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0; vector<vector<int>> dp(n, vector<int>(71, 0));
    for(int i = 0; i < n; i++) {
      dp[i][a[i]] = 1;
      for(int g = 1; g < 71; g++) {
        for(int j = 0; j < i; j++) {
          (dp[i][__gcd(g, a[i])] += dp[j][g]) %= MOD; 
        }
      }
      for(int g = 1; g < 71; g++) {
        (ans += (g * dp[i][g])) %= MOD;
      }
      dbg(ans);
    }
    cout << ans << endl;
  }  
}



