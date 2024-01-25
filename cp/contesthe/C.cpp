/**
 * File              : C.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 13.07.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}void __print(long x) {cerr << x;}void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");}template<typename T, typename V>void __print(const pair<T, V> &x);template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}template<typename T, typename V>void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}void _print() {cerr << "]\n";}template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...)     cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
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
#define mod           998244353
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

int a[MAXN], n, sum = 0;
int f[MAXN] = {0}, g[MAXN] = {0};

int powMod(int b, int p) {
  int x = 1, y = b;
  while(p > 0) {
    if(p & 1) {
      x = (x * y) % mod;
    }
    y = (y * y) % mod;
    p >>= 1;
  }
  return x % mod;
}

signed main() {
  TLE;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = sum / 2; j >= a[i]; j--) {
      (f[j] += f[j - a[i]]) %= mod;
      (g[j] += g[j - a[i]] * 2 + f[j - a[i]] * 2) %= mod;
    }
    f[a[i]]++;
  }
  int ans = 0;
  for(int i = 0; i <= sum / 2; i++) {
    (ans += g[i]) %= mod;
  }
  int res = (powMod(3ll, n) - 3 * powMod(2ll, n) + 3) % mod;
  cout << ((res - ans * 3) % mod + mod) % mod;
  
}

