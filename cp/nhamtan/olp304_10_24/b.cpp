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

class dsu {

public:
  vector<int> parent, size;
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
  int n, m, k;
  cin >> n >> m >> k;
  dsu dsu(n + 1);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    dsu.unite(u, v);
  }
  set<int, greater<int>> st[n + 1];
  for(int i = 1; i <= n; i++) {
    st[adj[i].size()].insert(dsu.find(i));
  }
  int ans = 0;
  for(int pipe = 0; pipe <= n; pipe++) {
    int cnt = 0, curr = 0;
    for(auto it = st[pipe].begin(); it != st[pipe].end(); it++) {
      cnt++;
      if(cnt > k) 
        break;
      curr += dsu.size[*it];
    }
    ans = max(ans, curr);
  }
  cout << ans << '\n';
  
}


