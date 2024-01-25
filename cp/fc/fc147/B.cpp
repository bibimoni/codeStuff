/**
 * File              : B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 21.05.2023
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

int fact(int n) {
//  if(n >= mod) return 0;
  int res = 1;
  for(int i = 1; i <= n; i++) {
    res = (res * i) % mod;
  }
  return res;
}

int modpow(int a, int b) {
  int x = 1; int y = a;
  while(b > 0) {
    if(b & 1) {
      x = (x * y) % mod;
    }
    y = (y * y) % mod;
    b >>= 1;
  }
  return x % mod;
}

signed main() {
  FAST;
  int n; cin >> n;
  if(n == 1) {
    cout << 0;
    return 0;
  }
  if(n == 2) {
    cout << 2;
    return 0;
  }
  if(n >= 3) {
    cout << modpow(10, n) + modpow(8, n) - ((2 * modpow(9, n)) % mod);
  }
}

