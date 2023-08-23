/**
 * File              : companyqueries2_1.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 15.07.2023
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
#define MAX_N          (int) 1e6 + 5
#define MAX_L         30
int nxt() {int n; cin >> n; return n;}
int n, q, idx;
int dep[2 * MAX_N], euler[2 * MAX_N], first[MAX_N], lg[2 * MAX_N];
array<int,2> dp[2 * MAX_N][MAX_L]; 
vector<int> adj[MAX_N];

void dfs(int u, int p = 0, int h = 0) {
  euler[++idx] = u;
  dep[idx] = h;
  first[u] = idx;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u, h + 1);
      euler[++idx] = u;
      dep[idx] = h;
    }
  }
}

int min_query(int l, int r) { 
  int k = lg[r - l + 1];
  return min(dp[l][k], dp[r - (1 << k) + 1][k])[1];
}
 
int lca(int u, int v) {
  int l = first[u], r = first[v];
  if (l > r) swap(l, r);
  return min_query(l, r);
}

signed main() {
  TLE;
  cin >> n >> q;
  for (int v = 2; v <= n; v++) {
    adj[nxt()].push_back(v);
  }
  dfs(1);
  lg[1] = 0;
  for(int i = 2; i <= 2 * n; i++) 
    lg[i] = lg[i / 2] + 1;
  for(int i = 1; i <= 2 * n; i++)
    dp[i][0] = {dep[i], euler[i]};
  for(int j = 1; j < MAX_L; j++)
    for(int i = 1; i + (1 << j) <= 2 * (n + 1); i++)
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
  while (q--) {
    int a, b; cin >> a >> b;
    cout << lca(a, b) << "\n";
  }
}

