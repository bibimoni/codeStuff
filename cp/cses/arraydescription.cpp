/**
 * File              : arraydescription.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 29.05.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

signed main() {
  FAST;
  int n, m; cin >> n >> m;
  int a[n + 1]; for(int i = 1; i <= n; i++) cin >> a[i];
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  //dp[i][j] number of array at i with x[i] = j
  if(a[1] == 0) {
    for(int i = 1; i <= m; i++) {
      dp[1][i] = 1;
    }
  }
  else {
    dp[1][a[1]] = 1;
  }
  for(int i = 2; i <= n; i++) {
    if(a[i] == 0) {
      for(int j = 1; j <= m; j++) {
        (dp[i][j] += dp[i - 1][j]) %= mod;
        if(j - 1 >= 1) {
          (dp[i][j] += dp[i - 1][j - 1]) %= mod;
        }
        if(j + 1 <= m) {
          (dp[i][j] += dp[i - 1][j + 1]) %= mod;
        }
        dbg(dp[i][j]);
      }
    }
    if(a[i] != 0) {
      (dp[i][a[i]] += dp[i - 1][a[i]]) %= mod;
      if(a[i] - 1 >= 1) {
        (dp[i][a[i]] += dp[i - 1][a[i] - 1]) %= mod;
      }
      if(a[i] + 1 <= m) {
        (dp[i][a[i]] += dp[i - 1][a[i] + 1]) %= mod;
      }
      dbg(dp[i][a[i]]);
    }
  }
  int res = 0;
  for(int i = 1; i <= m; i++) {
    (res += dp[n][i]) %= mod;
  }
  cout << res;
}

