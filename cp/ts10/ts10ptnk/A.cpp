/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 01.06.2023
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

bool cmp1(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}


signed main() {
  FAST;
  freopen("CAKE.INP", "r", stdin);
  freopen("CAKE.OUT", "w", stdout);
  int n, m; cin >> n >> m;
  int k; cin >> k;
  vector<pair<int, int>> coords;
  for(int i = 0; i < 4 * k; i++) {
    coords.push_back({nxt(), nxt()});
  }
  sort(coords.begin(), coords.end(), cmp1);
  int rows = coords[k * 2].first - coords[k * 2 - 1].first;
  sort(coords.begin(), coords.end(), cmp2);
  int cols = coords[k * 2].second - coords[k * 2 - 1].second;
  cout << (rows * cols);
  
}

