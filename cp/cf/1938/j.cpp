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
#define int long long
const int N = (int) 1e5 + 5, INF = (int) 2e9;
vector<pair<int, int>> adj[N];
map<pair<int, int>, int> dist, save;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    adj[u].push_back({t, v});
    adj[v].push_back({t, u});
    dist[{u, v}] = t;
    dist[{v, u}] = t;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> d(n + 1, INF), trace(n + 1, -1);
  pq.push({0, 1});
  d[1] = 0;
  while(!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();
    if(d[u] != w)
      continue;
    for(auto [t, v] : adj[u]) {
      if(d[v] > d[u] + t) {
        d[v] = d[u] + t;
        trace[v] = u;
        pq.push({d[v], v});
      }
    }
  }
  if(d[n] == INF) {
    cout << "-1\n";
    return 0;
  }
  vector<int> path;
  int u = n;
  vector<int> mark(n + 1, 0), id(n + 1, 0);
  path.push_back(u);
  mark[u] = mark[1] = 1;
  while(trace[u] != 1) {
    path.push_back(trace[u]);
    u = trace[u];
    mark[u] = 1;
  }
  path.push_back(1);
  if(path.size() - 1 == m || d[n] == INF) {
    cout << "-1\n";
    return 0;
  }
  pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
  vector<int> dn = vector<int>(n + 1, INF);
  pq.push({0, n});
  dn[n] = 0;
  while(!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();
    if(dn[u] != w)
      continue;
    for(auto [t, v] : adj[u]) {
      if(dn[v] > dn[u] + t) {
        dn[v] = dn[u] + t;
        pq.push({dn[v], v});
      }
    }
  }
  int curr = INF;
  u = n; int nxt = -1;
  while(u != -1) {
    int pre = trace[u];
    for(auto [t, v] : adj[u]) {
      if(v != pre && v != nxt) {
        curr = min(curr, d[u] + t + dn[v]);
      }
    }
    nxt = u;
    u = pre;
  }
  if(curr == INF) {
    cout << "-1\n";
    return 0;
  }
  cout << curr + d[n];
}

