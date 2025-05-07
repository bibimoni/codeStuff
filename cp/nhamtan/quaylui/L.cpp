/**
 * File              : L.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 16.07.2023
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

int mat[4][4];
int ans = 0;
int d[5] = {1, 0, -1, 0, 1};
bool check(int x, int y) {
  return x <= 3 && y <= 3 && x >= 1 && y >= 1;
}

vector<vector<bool>> vis(4, vector<bool>(4, false));

void Try(int cnt, int x, int y, int curr) {
  //dbg(x, y, curr, cnt);
  if(cnt == 10) {
    ans = max(ans, curr);
    return;
  }
  for(int i = 0; i < 4; i++) {
    int u = x + d[i];
    int v = y + d[i + 1];
    if(!check(u, v) || vis[u][v]) continue;
    vis[u][v] = true;
    //dbg(u, v);
    Try(cnt + 1, u, v, curr * 10 + mat[u][v]);
    vis[u][v] = false;
  }
  
}

signed main() {
  TLE;
  MULTI {
    int x, y;
    vector<vector<bool>> tmp(4, vector<bool> (4, false));
    vis = vector<vector<bool>>(all(tmp));
    for(int i = 1; i <= 3; i++) 
      for(int j = 1; j <= 3; j++) {
        cin >> mat[i][j];
      }  
    //dbg('a');
    //vis[1][1] = true;
    ans = 0;
    for(int i = 1; i <= 3; i++)
      for(int j = 1; j <= 3; j++) {
        vis[i][j] = true;
        Try(2, i, j, mat[i][j]);
        vis[i][j] = false;
      }
    cout << ans << endl;
  }
}

