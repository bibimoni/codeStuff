/**
 * File              : DT1.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 21.06.2023
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

#define all(x) x.begin(), x.end()
#define int long long
#define mod 1000000007
#define endl '\n'
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}
int a[1010][1010] = {0}, dp[1010][1010] = {0};
signed main() {
  TLE;
  int m, n; cin >> m >> n;
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(i <= m - 1) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j]; 
      }
      else {
        dp[i][j] = dp[i - 1][j] + a[i][j];
      }
    }
  }
  int Max = 0;
  int x = -1, y = m - 1;
  for(int i = 1; i <= n; i++) {
    if(Max < dp[m][i]) {
      Max = dp[m][i];
      x = i;
    }
  }
  cout << Max << endl;
  vector<pair<int, int>> path;
  path.push_back({m, x});
  while(x != 1 || y != 1) {
    path.push_back({y, x});
    if(y == 1) {
      x--;
    }
    else {
      //remove the "=" here, WA test 3
      //fuck
      if(dp[y][x - 1] >= dp[y - 1][x]) {
        x--;
      }
      else {
        y--;
      }
    }
  }
  path.push_back({1, 1});
  reverse(all(path));
  for(pair<int, int> p : path) {
    cout << "(" << p.first << "," << p.second << ")" << endl;
  }
}

