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

const int N = 10011;
int parent[N];
struct Edge {
  int u, v, c;
};
vector<Edge> a;
int findSet(int u) {
  return u == parent[u] ? u : parent[u] = findSet(parent[u]);
}

bool unionSet(int u, int v) {
  u = findSet(u), v = findSet(v);
  if(u == v) return false;
  parent[v] = u;
  return true;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) parent[i] = i;
  for(int i = 0, u, v, c; i < m; i++) {
    cin >> u >> v >> c;
    a.pb({u, v, c});
  }
  sort(all(a), [&] (Edge b, Edge c) {
    return b.c < c.c;
  });
  int ans = 0;
  for(auto [u, v, c] : a) {
    if(unionSet(u, v)) ans += c;
  }
  cout << ans;
}



