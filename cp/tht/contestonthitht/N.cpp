/**
 * File              : N.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 30.05.2023
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
#define MAXN (int) 1e5 + 5
#define INF 1e18
int nxt() {int n; cin >> n; return n;}

vector<vector<pair<int, int>>> adj(MAXN);
vector<int> d(MAXN, INF);
vector<int> trace(MAXN);
vector<int> Max(MAXN);
vector<int> Min(MAXN);
int n, m;

signed main() {
  FAST;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({c, v});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  trace[1] = 1;
  d[1] = 0;
  d[0] = 0;
  Q.push({0, 1});
  while(!Q.empty()) {
    int w = Q.top().first;
    int u = Q.top().second; 
    Q.pop();
//    dbg(w, u);
    if(w > d[u]) continue;
    for(auto p : adj[u]) {
      int v = p.second;
      int w1= p.first;
//      dbg(v, w1, d[u], d[v]);
      if(d[u] + w1 < d[v]) {
        d[v] = d[u] + w1;
        Max[v] = Max[u] + 1;
        Min[v] = Min[u] + 1;
        trace[v] = trace[u];
//        dbg(v, trace[v]);
        Q.push({d[v], v});
      }
      else if(d[u] + w1 == d[v]) {
        Max[v] = max(Max[v], Max[u] + 1);
        Min[v] = min(Min[v], Min[u] + 1);
        trace[v] = (trace[u] + trace[v]) % mod;
//        dbg(v, trace[v]);
      }
//      dbg(v, w1, d[u], d[v]);
    }
  }
  if(d[n] == INF) {
    cout << -1;
  }
  else {
    cout << d[n] << ' ' << trace[n] << ' ' << Min[n] << ' ' << Max[n];
  }
}

