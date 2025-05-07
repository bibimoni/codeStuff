/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 02.06.2023
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
  freopen("MARBLE.INP", "r", stdin);
  freopen("MARBLE.OUT", "w", stdout);
  int n; 
  cin >> n; int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int m;
  cin >> m; int b[m]; 
  for(int i = 0; i < m; i++) cin >> b[i];
  int ans = 0;
  int l = n - 1;
  for(int i = 1; i < n; i++) {
    if(a[i - 1] > a[i]) {
      l = i - 1;
    }
  }
  int r = 0;
  for(int i = m - 2; i >= 0; i--) {
    if(b[i + 1] < b[i]) {
      r = i + 1;
    }
  }
  dbg(l, r);
  for(int i = 0; i <= l; i++) {
    int j = r;
    bool check = false;
    while(a[i] > b[j]) {
      j++;
      if(j > m) {
        check = true;
        break;
      }
    }
    if(check) break;
    ans = max(ans, i + 1 + (m - j));    
    dbg(i, j, i + 1, m - j);
    
  }
  cout << ans;
}
//
