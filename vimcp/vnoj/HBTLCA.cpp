/**
 * File              : HBTLCA.cpp
 * Author            : distiled
 * Date              : 15.07.2023
 * Last Modified Date: 09.08.2023
 * Last Modified By  : distiled
 */
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
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define N             (int) 1e6 + 5
int nxt() {int n; cin >> n; return n;}
 
int n, q;
vector<int> adj[N];
/**
 * Description: Finding LCA and Kth Ancestor using Binary Lifting
 * Caution:
 *    * adj must be one-indexed
 *    * root must be 1 (can be modified if required)
 * Source : https://oj.vnoi.info/submission/4618381
 * Verification : https://oj.vnoi.info/problem/hbtlca
 * 
 * usage LCA lca(n + 1, root) // default root is 1
 */

struct LCA {
  vector<vector<int>> par;
  vector<int> dep;
  int LG; 
  void dfs(int u, int p = 0) {
    par[u][0] = p;
    for (int i = 1; i < LG; i++) 
      par[u][i] = par[par[u][i - 1]][i - 1];
    for (int v : adj[u]) {
      if (v == p) continue;
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
 
  int ancestor(int u, int k) {
    for (int i = 0; i < LG; i++) 
      if (k & (1 << i)) 
        u = par[u][i];
    return u;
  }
 
  int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = ancestor(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = LG - 1; i >= 0; i--)
      if (par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];
  }
 
  LCA (int _n, int root = 1) {
    int n = _n;
    LG = 64 - __builtin_clzll(n);
    par.assign(n, vector<int>(LG, 0));
    dep.assign(n, 0);
    dfs(root);
  }
};

signed main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(cin >> n) {
    if(n == 0) break;
    for(int i = 1; i <= n; i++) adj[i].clear();
    int root = 1;
    for(int i = 1, u, v; i < n; i++) {
      cin >> u >> v;
      adj[v].push_back(u);
      adj[u].push_back(v);
    } 
    LCA lca(n + 1, root);
    MULTI {
      char type; cin >> type;
      if(type != '?') {
        root = nxt();
      }
      else {
        int a, b; cin >> a >> b;
        int rA = lca.lca(root, a), rB = lca.lca(root, b);
        if(lca.dep[rA] < lca.dep[rB]) swap(rA, rB);
        int ab = lca.lca(a, b);
        int res = (lca.dep[ab] >= lca.dep[rA] ? ab : rA);
        cout << res << endl;
      }
    }
  } 
}

