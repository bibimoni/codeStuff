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

const int N = 111, MOD = (int) 2023;

int add(int num, int val) {
  num += val;
  if(num >= MOD) {
    num -= MOD;
  }
  if(num < 0) {
    num += MOD;
  }
  return num;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n]; 
  for(int i = 0; i < n; i++) cin >> a[i]; 
  sort(a, a + n);
  vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));
  for(int i = 0; i < n; i++) {
    dp[i][i][0] = 1;
  }
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      for(int k = 0; k < n; k++) {
        if(dp[i][j][k] == 0) continue;
        for(int m = j + 1; m < n; m++) {
          if(__gcd(a[m], a[j]) == 1) {
            dp[i][m][k + 1] = add(dp[i][m][k + 1], dp[i][j][k]); 
          }
        }
      }
    }
  }
  MULTI {
    int u, v, k; cin >> u >> v >> k;
    int i = -1, j = -1;
    for(int idx = 0; idx < n; idx++) {
      if(a[idx] == u) i = idx;
      if(a[idx] == v) j = idx;
    }
    cout << dp[i][j][k] % MOD << endl;
  }
}



