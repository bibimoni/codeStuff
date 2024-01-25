/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

const int N = (int) 1e5 + 5, INF = (int) 2e9;
vector<int> d(N, INF); vector<pair<int, int>> adj[N];
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  d[1] = 0;
  q.push({0, 1});
  while(!q.empty()) {
    auto [w, u] = q.top(); q.pop();
    if(d[u] < w) continue;
    for(auto [v, w1] : adj[u]) {
      if(d[u] + w1 < d[v]) {
        d[v] = min(d[u] + w1, d[v]);
        q.push({v, d[v]});
      }
    }
  }
  cout << (d[n] == INF ? -1: d[n]);
}



