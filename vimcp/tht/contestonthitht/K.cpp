/**
 * File              : K.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 30.05.2023
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
const int maxs = 1000;

signed main() {
  FAST;
  int n; cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) cin >> a[i];
  vector<vector<int>> dp(101, vector<int>(maxs + 5, 0));
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    for(int j = 1; j <= maxs; j++) {
      (dp[i][j] += dp[i - 1][j]) %= mod;
      if(j >= a[i]) {
        (dp[i][j] += dp[i - 1][j - a[i]]) %= mod;
      }
    }
  }
  vector<int> pre(maxs, 0);
  pre[0] = dp[n][0];
  for(int s = 1; s <= maxs; s++) {
    int cnt = 0;
    (pre[s] = pre[s - 1] + dp[n][s]) %= mod;
  }
  MULTI {
    int l, r; cin >> l >> r;
    cout << (pre[r] - pre[l - 1] + mod) % mod << endl;
  }
}

