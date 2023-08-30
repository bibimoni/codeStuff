/**
 * File              : C.cpp
 * Author            : distiled
 * Date              : 29.08.2023
 * Last Modified Date: 29.08.2023
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

bool check(int a, int b) {
  while(a != 0 || b != 0) {
    if((a & 1) && (b & 1)) return false;
    a >>= 1;
    b >>= 1;
  }
  return true;
}

int makeCurrState(int num) {
  int curr = 0;
  while(num > 0) {
    if(curr >> (num % 10) & 1) {
      return 0;
    }
    else {
      curr |= (1 << (num % 10));
    }
    num /= 10;
  }
  return curr;
}

signed main() {
  TLE;
  MULTI { 
    int n; cin >> n;
    vector<vector<int>> dp(n, vector<int>(1 << 11, 0));
    int a[n], res = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    int state = makeCurrState(a[0]);
    if(state) {
      dp[0][state] = ((!state) ? 0 : a[0]);  
    }
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < (1 << 11); j++) {
        int state = makeCurrState(a[i]);
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        res = max({res, dp[i][j]});
        if(!check(j, state) || !state) continue;
        dp[i][j | state] = max(dp[i][j | state], dp[i - 1][j] + a[i]);
        res = max({res, dp[i][j | state]});
      }
    }
    cout << res << endl;
  }
}

