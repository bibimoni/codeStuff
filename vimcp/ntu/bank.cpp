/**
 * File              : bank.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 03.07.2023
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
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

struct customer {
  int c, t;
};

signed main() {
  TLE;
  int n; cin >> n;
  customer a[n + 1];
  int maxTime = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i].c >> a[i].t;
    maxTime = max(maxTime, a[i].t);
  }
  sort(a + 1, a + n + 1, [&] (customer b, customer c) {
      return b.t < c.t;
    });
  vector<vector<int>> dp(n + 1, vector<int>(maxTime + 1, 0));
  for(int i = 1; i <= n; i++) { 
      dp[i][0] = max(dp[i - 1][0], a[i].c);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= maxTime; j++) {
      if(a[i].t >= j)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i].c);
      else 
        dp[i][j] = dp[i - 1][j];
//      cout << dp[i][j] << ' ';
    }
//    cout << endl;
  }
  int ans = 0;
  for(int t = 0; t <= maxTime; t++) {
    ans = max(ans, dp[n][t]);
  }
  cout << ans;
}

