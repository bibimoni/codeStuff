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
int a[N], n, m;
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
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m;
  dsu dsu(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    if(a[u] > a[v]) swap(u, v);
    adj[u].push_back(v);
  }
  set<pair<int, int>> s;
  vector<int> d(n + 1, 0);
  s.insert({-1, 1});
  d[1] = -1;
  while(s.size()) {
    auto [w, u] = *s.begin();
    s.erase(s.begin());
    u = dsu.find(u);
    if(d[u] < w) continue;
    for(int v : adj[u]) {
      if(a[u] == a[v]) dsu.unite(u, v);
      v = dsu.find(v);
      if(d[v] > d[u] - (a[u] != a[v])) {
        d[v] = d[u] - (a[u] != a[v]);
        s.insert({d[v], v});
      }
    }
  }
  cout << -d[dsu.find(n)];
}


