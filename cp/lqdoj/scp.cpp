/**
 * https://lqdoj.edu.vn/problem/scp
 * File              : scp.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 31.07.2023
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
#define mod 998244353
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

signed main() {
  FAST;
  int n; cin >> n;
  int cnt = 0;
  int start = (int) floor(sqrt(n)) % mod;
  cnt += (((start % mod) * ((start + 1) % mod)) / 2) % mod;
  start++;
  int end = (int) floor((n + 1) / 2) % mod;
//  dbg(start, cnt);
  int x = (start % mod - sqrt((start * start) % mod - n % mod));
  int prev = start;
  while(x >= 1) {
    int i = ((x * x + n) / (2 * x)) % mod;
    if(i >= start && i <= end) {
//      dbg(i, x, (x * (i - prev + 1)));
      cnt += ((x % mod) * ((i - prev + 1) % mod)) % mod;
      x--;
      prev = (i + 1) % mod;
    }
    else break;
  }
  cout << cnt;
}
