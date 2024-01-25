/**
 * File              : graycode.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 13.06.2023
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
int n;

signed main() {
  FAST;
  // 0    0    0_0    00
  // 1 -> 1 -> 1_0 -> 10
  // 0    1    1_1    11
  // 1    0    0_1    01
  // 00     00_0 
  // 10     10_0
  // 11     11_0
  // 01     01_0
  // 01  -> 01_1
  // 11     11_1
  // 10     10_1
  // 00     00_1
  cin >> n;
  vector<string> res;
  res.push_back("");
  for(int i = 0; i < n; i++) {
    int m = res.size();
    for(int j = m - 1; j >= 0; j--) {
      res.push_back(res[j]);
    }
    m *= 2;
    for(int j = 0; j < m; j++) {
      if(j < res.size() / 2) {
        res[j] += "0";
      }
      else {
        res[j] += "1";
      }
    }
  }
  for(auto t: res) {
    cout << t << endl;
  }
}

