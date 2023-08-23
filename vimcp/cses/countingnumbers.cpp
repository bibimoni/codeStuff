/**
 * File              : countingnumbers.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 25.06.2023
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
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

int a[23];
vector<vector<int>> dp(23, vector<int>((int) 1 << 20, -1));

void decToBin(int x) {
  string s = "";
  while(x > 0) {
    s += (x % 2) + '0';
    x /= 2;
  }
  reverse(all(s));
  cout << s << endl;
}

int dfs(int i, bool lim, int prevDigit = -1) {
//  decToBin(mask);
  if(i < 0) {
    return 1;
  }
  if(!lim && prevDigit >= 0 && dp[i][prevDigit] >= 0) {
    return dp[i][prevDigit];
  }
  int maxD = (lim ? a[i] : 9);
  int ret = 0;
  for(int c = 0; c <= maxD; c++) {
    bool limD = lim && (c == maxD);
    if(c == prevDigit) continue; 
    ret += dfs(i - 1, limD, c);
  }
  if(lim) dp[i][prevDigit] = ret;
  return ret;
}

int G(int x) {
  if(x == 0) return 0;
  a[0] = 0;
  int n = 0;
  while(x > 0) {
    a[n] = x % 10;
    x /= 10;
    n++;
  }
//  dbg(a[2], a[1], a[0]);
  return dfs(n - 1, true, a[n - 1]);
}

signed main() {
  FAST;
//  int a, b; cin >> a >> b;
//  cout << G(b) - G(a - 1);
  dbg(G(100));
}

