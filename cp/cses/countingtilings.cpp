/**
 * File              : countingtilings.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 22.06.2023
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

int n, m, k, u, v, dp[1025][1025] = {0}, a[2][1025];

void calc_profile(int p, int p2, int sz) {
  if(sz == n) {
    dp[p][p2] = 1; return;
  }
  if((p & (1 << sz)) == 0) {
    calc_profile(p, p2 + (1 << sz), sz + 1);
    if(sz < n - 1) {
      if((p & (1 << (sz + 1))) == 0) calc_profile(p, p2, sz + 2);
    }
  }
  else {
    calc_profile(p, p2, sz + 1);
  }
  return;
}

signed main() {
  FAST;
  cin >> n >> m;
  if(n > m) swap(n, m);
  k = 1 << n;
  for(int i = 0; i < k; i++) {
    calc_profile(i, 0, 0);
  }
  a[0][0] = 1; u = 0; v = 1;
  for(int q = 1; q <= m; q++) {
    for(int i = 0; i < k; i++) {
      for(int j = 0; j < k; j++) {
        (a[v][i] += (a[u][j] % mod) * (dp[j][i] % mod)) %= mod;
      }
    }
    u ^= 1; v ^= 1;
    for(int ii = 0; ii < k; ++ii) a[v][ii] = 0;
  }
  cout << a[u][0];
}

