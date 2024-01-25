/**
 * File              : C.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 14.07.2023
 * Last Modified By  : distiled
 */
//van de ky nang
#include<bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}void __print(long x) {cerr << x;}void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");}template<typename T, typename V>void __print(const pair<T, V> &x);template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}template<typename T, typename V>void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}void _print() {cerr << "]\n";}template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...)     cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

struct Edge {
  int u, v, c;
  Edge(int _u, int _v, int _c): u(_u), v(_v), c(_c) {};
};

struct Dsu {
  vector<int> parent;

  void init(int n) {
    parent.resize(n + 5, 0);
    for(int i = 1; i <= n; i++) parent[i] = i;
  }
  
  int findSet(int u) {
    return parent[u] == u ? u : parent[u] = findSet(parent[u]);
  }

  void join(int u, int v) {
    u = findSet(u); v = findSet(v);
    if(u == v) return;
    parent[v] = u;
  }
} dsu;

vector<Edge> edges;

signed main() {
  TLE;
  MULTI {
    int n, m, q; cin >> n >> m >> q;
    for(int i = 0, u, v, w; i < m; i++) {
      cin >> u >> v >> w;
      edges.push_back(Edge(u, v, w)); 
    }
    while(q--) {
      int k, s; cin >> k >> s; k--;
      vector<Edge> temp;
      temp.assign(all(edges));
      dsu.init(n);
      for(int i = 0, t, c; i < s; i++) {
        cin >> t >> c; t--;
        temp[t].c = c;
      }
      for(int i = 0; i < m; i++) {
        if(temp[i].c >= temp[k].c) continue;
        dsu.join(temp[i].u, temp[i].v);
      }
      if(dsu.findSet(temp[k].u) == dsu.findSet(temp[k].v)) {
        YES
      }
      else {
        NO
      }
    }
  }
}

