
/**
 * File              : maildelivery.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 15.07.2023
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
  int n, m; cin >> n >> m;
  set<int> adj[n + 1]; 
  map<int, bool> f;
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v; 
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for(int i = 1; i <= n; i++) {
    if(adj[i].size() & 1) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  vector<int> res;
  stack<int> Q; Q.push(1);
  while(!Q.empty()) {
    int u = Q.top();
    if(adj[u].empty()) {
      res.push_back(u);
      Q.pop();
    }
    else {
      int v = *adj[u].begin();
      adj[u].erase(v);
      adj[v].erase(u);
      Q.push(v);
    }
  }
  if((int) res.size() != m + 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for(int i : res) cout << i << ' ';
}
 

