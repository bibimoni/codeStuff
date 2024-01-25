/**
 * File              : thidau.cpp
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
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
  int n, k; cin >> n >> k;
  int a[n], b[n];
  set<int> distances;
  map<int, bool> check;
  for(int i = 0; i < n; i++) cin >> a[i], check[a[i]] = true;
  for(int i = 0; i < n; i++) cin >> b[i];
  
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      distances.insert(a[j] - a[i]);
    }
  }
  
  vector<int> dp(a[n - 1] + 1, 0);
  for(int i = 0; i < n; i++) {
    dp[a[i]] = b[i];
  }
  for(int i = 0; i < n; i++) {
    for(auto dis : distances) {
      if(dis >= k && a[i] - dis >= 0 && check[a[i] - dis]) {
        dp[a[i]] = max(dp[a[i]], dp[a[i] - dis] + b[i]);
      }
    }
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, dp[a[i]]);
  }
  cout << ans;
}

