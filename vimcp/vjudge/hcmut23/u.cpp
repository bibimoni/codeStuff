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

const int N = (int) 1e5 + 5;
int parent[N], enemy[N];
int findSet(int u) {
  return u == parent[u] ? u : parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
  u = findSet(u), v = findSet(v);
  if(u == v) return;
  parent[v] = u;
}


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) parent[i] = i, enemy[i] = 0;
  for(int i = 0; i < m; i++) {
    char type; cin >> type;
    int u, v; cin >> u >> v;
    if(type == 'F') {
      unionSet(u, v);
    }
    else {
      if(enemy[u]) unionSet(v, enemy[u]);
      if(enemy[v]) unionSet(u, enemy[v]);
      enemy[u] = v;
      enemy[v] = u;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) ans += (i == parent[i]);
  cout << ans;
}



