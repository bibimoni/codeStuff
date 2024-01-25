/**
 * File              : B1.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 20.05.2023
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
 
int ans = 0;
map<int, bool> f;
int reverseNum(int num) {
  int temp = 0;
  while(num != 0) {
    temp = temp * 10 + num % 10;
    num /= 10;
  }
  return temp;
}
 
bool check(int num, int k) {
  if(f[num]) return false;
  f[num] = true;
  string num1 = "";
  while(num != 0) {
    num1 += (num % 10) + '0';
    num /= 10;
  }
  string k1 = "";
  if(k == 0) k1 = "0";
  else {
    while(k != 0) {
      k1 += (k % 10) + '0';
      k /= 10;
    }
  }
//  dbg(num1, k1, k);
  return (num1.find(k1) != string::npos);
}
 
signed main() {
  FAST;
  int k, l, r; cin >> k >> l >> r;
  int k1 = reverseNum(k);
  int res = 0;
  for(int i = l; i <= r; i++) {
    if(check(i, k)) {res++; dbg(i);}
    if(k >= 10 && check(i, k1)) {res++; dbg(i);}
  }
  cout << res;
}
 
