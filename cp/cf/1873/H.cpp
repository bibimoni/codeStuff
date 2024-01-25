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

const int N = (int) 2e5 + 5, INF = (int) 2e9;
vector<int> adj[N];
bool vis[N]; int parent[N], entryNode = -1;
vector<int> d(N, INF);

void dfs(int u, int p = -1) {
  vis[u] = true;
  if(entryNode != -1) return;
  for(int v : adj[u]) {
    if(v == p) continue;
    if(vis[v]) {
      if(entryNode == -1) entryNode = v;
      return;
    }
    dfs(v, u);
  }
}

void findPath(int src) {
  set<pair<int, int>> q;
  q.insert({0, src});
  d[src] = 0;
  while(q.size()) {
    auto [w, u] = *q.begin();
    q.erase(q.begin());
    for(int v : adj[u]) {
      if(d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        q.insert({d[v], v});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, a, b; cin >> n >> a >> b;
    memset(vis, false, sizeof vis);
    d = vector<int>(N, INF);
    entryNode = -1;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 1, u, v; i <= n; i++) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if(a == b) {
      cout << "NO\n";
      continue;
    }
    dfs(b);
    findPath(entryNode);
    if(d[a] <= d[b]) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
}

