/**
 * File              : seg.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 18.06.2023
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

#define all(x) x.begin(), x.end();
#define int long long
#define mod 1000000007
#define endl '\n'
#define TLE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
  int n; cin >> n;
  int sum = 0, a[n];
  for(int i = 0; i < n; i++) {
    a[i] = nxt();
    sum += a[i];
  }
  int cnt = 0;
  int curr = 0;
  int sumPart = 0;
  for(int i = 1; i <= n; i++) {
    if(sum % i != 0) continue;
    sumPart = sum / i;
    curr = 0;
    bool check = true;
    for(int j = 0; j < n; j++) {
      curr += a[j];
      if(curr == sumPart) {
        curr = 0;
      }
      else if(curr > sumPart) {
        check = false;
        break;
      }
    }
    dbg(sumPart, i, curr);
    if(curr == 0 && check) {
      cnt = i;
    }
  }
  cout << cnt;
}

