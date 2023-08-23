/**
 * File              : taitrong.cpp
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
#define MAXN (int) 1e3 + 5
int nxt() {int n; cin >> n; return n;}
int n, m, s, t;

struct node {
  int u; 
  int w;
};

vector<vector<node>> adj(MAXN);

struct cmp {
  bool operator() (node a, node b) {
    return a.w > b.w;
  }
};

bool _(int val) {
  priority_queue<node, vector<node>, cmp> Q;
  vector<int> d(MAXN, 1e9);
  vector<bool> visited(MAXN, false);
  d[s] = 0;
  Q.push({s, d[s]});
  while(!Q.empty()) {
    auto x = Q.top();
    Q.pop();
    if(visited[x.u]) continue;
    visited[x.u] = true;
    for(auto v: adj[x.u]) {
      if(d[v.u] > d[x.u] + v.w && v.w >= val) {
        d[v.u] = d[x.u] + v.w;
        Q.push({v.u, d[v.u]});
      }
    }
  }
  if(d[t] == 1e9) return false;
  return true;
}

signed main() {
  FAST;
  freopen("TAITRONG.INP", "r", stdin);
  freopen("TAITRONG.OUT", "w", stdout);
  cin >> n >> m >> s >> t;
  for(int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  int l = 0, r = 1e9;
  int ret = -1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(_(mid)) {
      l = mid + 1;
      ret = mid; 
    }
    else r = mid - 1;
  }
  cout << ret;
}

