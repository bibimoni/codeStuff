// time-limit: 3000
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
#define all(_x) (_x).begin(), (_x).end()

const int N = (int) 2e5 + 5;
vector<int> adj[N];
int cnt[N];
bool vis[N];

class dsu {
  vector<int> parent, size;

public:
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
  }
 
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
 
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
      return true;
    } else {
      return false;
    }
  }
};

int count(int u) {
  int ret = 1;
  vis[u] = true;
  for(int v : adj[u]) {
    if(!vis[v]) {
      ret += count(v);
    }
  }
  return ret;
}

vector<int> cycles;
bool dfs(int u, int dest, int p = -1) {
  cycles.push_back(u);
  if(u == dest) {
    return true;
  }
  for(int v : adj[u]) {
    if(v == p)
      continue;
    if(dfs(v, dest, u)) 
      return true;
  }
  cycles.pop_back();
  return false;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
      vis[i] = false;
    }
    vector<pair<int, int>> edges;
    for(int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      edges.push_back({u, v});  
    }    
    dsu dsu(n + 1);
    pair<int, int> cycle;
    int id = 0;
    for(auto [u, v] : edges) {
      if(dsu.unite(u, v)) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        id++;
      }
      else {
        cycle = {u, v};
        break;
      }
    }
    cycles.clear();
    dfs(cycle.first, cycle.second);
    // dbg(cycles, cycle, id);
    for(int i = id; i < n; i++) {
      auto [u, v] = edges[i];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int ans = n * (n - 1);
    for(int u : cycles) {
      vis[u] = true;
    }
    for(int u : cycles) {
      int t = count(u);
      ans -= (t - 1) * t / 2;
    }
    cout << ans << '\n';
  }
}


