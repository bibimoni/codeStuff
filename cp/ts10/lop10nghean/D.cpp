/**
 * File              : D.cpp
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

vector<int> diff((int) 1e6 + 5, 0);
vector<int> a((int) 1e6 + 5, 0);

signed main() {
  FAST;
  int n; cin >> n;
  int maxTime = 0, minTime = 1e9;
  for(int i = 0; i < n; i++) {
    int r, l; cin >> l >> r;
    maxTime = max(maxTime, r);
    minTime = min(minTime, l);
    diff[l]++;
    diff[r + 1]--;
  }
  int X = 0, Y = 0;
  
  for(int i = minTime; i <= maxTime; i++) {
    if(i == minTime) {
      a[i] = diff[i];
    }
    else {
      a[i] = diff[i] + a[i - 1];
    }
    X = max(a[i], X);
  }
  for(int i = minTime; i <= maxTime; i++) {
    if(a[i] == X) {
      Y++;
    }
  }
  cout << X << endl << Y;
}

