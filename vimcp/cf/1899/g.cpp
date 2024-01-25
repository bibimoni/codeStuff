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
#define all(x)         x.begin(), x.end() 

const int N = (int) 1e5 + 5, INF = (int) 1e18;
int timeDfs = 0;
vector<int> adj[N], tin, tout;
void dfs(int u, int p = -1) {
  tin[u] = ++timeDfs;
  for(auto v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
  }
  tout[u] = timeDfs;
}

set<int> st[4 * N];
int p[N];
set<int> merge(set<int> a, set<int> b) {
  a.insert(all(b));
  return a;
}

void build(int id, int l, int r) {
  if(l > r) return;
  if(l == r) {
    st[id].insert(tin[p[l]]);
    return;
  }
  int mid = (l + r) >> 1;
  build(id * 2, l, mid);
  build(id * 2 | 1, mid + 1, r);
  st[id] = merge(st[id * 2], st[id * 2 | 1]);
}
//find tin[x] <= tin[i] <= tout[i] <= tout[x],
//since we use dfs, if 2 element is from different branch tout[i] <= tin[x]
//so no need to check for tout[i] <= tout[x]
// => tin[x] <= tin[i] <= tout[x]
int query(int id, int l, int r, int u, int v, int x) {
  if(v < l || r < u) return INF;
  if(u <= l && r <= v) {
    auto pos = st[id].lower_bound(tin[x]);
    if(pos == st[id].end()) return INF;
    return *pos;
  }
  int mid = (l + r) >> 1;
  return min(query(id * 2, l, mid, u, v, x), query(id * 2 | 1, mid + 1, r, u, v, x));
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 1; i <= 4 * n; i++) st[i].clear();
    tin = vector<int>(n + 1, 0);
    tout = vector<int>(n + 1, 0);
    timeDfs = 0;
    for(int u, v, i = 0; i < n - 1; i++) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    dfs(1);
    dbg(tin, tout);
    
    build(1, 1, n);
    while(q--) {
      int l, r, x; cin >> l >> r >> x;
      cout << (query(1, 1, n, l, r, x) <= tout[x] ? "YES\n" : "NO\n"); 
    }
    cout << '\n';
    
  }
}


