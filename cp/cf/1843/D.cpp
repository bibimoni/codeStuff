/**
 * File              : D.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 21.06.2023
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
vector<int> d((int) 2e5 + 5);
vector<vector<int>> adj((int) 2e5 + 5);
void DFS(int src, int prev = -1) {
  if(adj[src].size() == 1 && src != 1) {
    d[src] = 1;
  }
  for(int v : adj[src]) {
    if(v != prev) {
      DFS(v, src);
      d[src] += d[v];  
    }
  }
}
signed main() {
  TLE;
  MULTI {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
      d[i] = 0;
      adj[i].clear();
    }
    for(int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    DFS(1);
    MULTI {
      int x, y; cin >> x >> y;
      cout << d[x] * d[y] << endl;
    }
  }
}

