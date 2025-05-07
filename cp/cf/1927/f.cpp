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
#define all(_x) (_x).begin(), (_x).end()
const int N = (int) 2e5 + 5;

vector<int> adj[N];
vector<array<int, 3>> edges;

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

bool ok;
vector<int> items, ans;

void dfs(int u, int dest, int p = -1) {
  items.push_back(u);
  if(u == dest) {
    ans = items;
    ok = true;
    return;
  }
  for(int v : adj[u]) {
    if(v == p) {
      continue;
    }
    dfs(v, dest, u);
    if(ok) {
      return;
    }
  }
  items.pop_back();
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    edges.clear();
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    for(int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end(), greater<array<int, 3>>());
    dbg(edges);
    dsu dsu(n + 1);
    array<int, 3> best;
    for(auto [w, u, v] : edges) {
      if(dsu.unite(u, v)) {
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      else {
        best = {w, u, v};
      }
    }
    ok = false;
    items = vector<int>();
    dfs(best[1], best[2]);
    cout << best[0] << ' ' << ans.size() << '\n';
    for(int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}

