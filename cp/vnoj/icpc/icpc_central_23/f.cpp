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

const int L = 20, N = (int) 1e6 + 5;

int n, up[N][L], h[N];
struct Road {
  int v, s, m;
};

vector<Road> adj[N];
void dfs(int u) {
  for(auto [v, s, m] : adj[u]) {
    if(v == up[u][0]) continue;
    h[v] = h[u] + 1;
    up[v][0] = u;
    for(int j = 1; j < L; j++) {
      up[v][j] = up[up[v][j - 1]][j - 1];
    }
    dfs(v);
  }
}

int lca(int a, int b) {
  if(h[a] != h[b]) {
    if(h[a] < h[b]) swap(a, b);
    int k = h[a] - h[b];
    for(int j = 0; (1 << j) <= k; j++) {
      if(k >> j & 1) {
        a = up[a][j];
      }
    }
  }
  if(a == b) return a;
  int k = __lg(h[a]);
  for(int j = k; j >= 0; j--) {
    if(up[a][j] != up[b][j]) 
      a = up[a][j], b = up[b][j];
  }
  return up[a][0];
}
vector<int> pref(N, 0);
int ans = 0;

void dfs1(int u, int p = -1) {
  for(auto [v, s, m] : adj[u]) {
    if(v == p) continue;
    dfs1(v, u);
    pref[u] += pref[v];
    ans += min(m, pref[v] * s);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n;
  for(int i = 0, u, v, s, m; i < n - 1; i++) {
    cin >> u >> v >> s >> m;
    adj[u].pb({v, s, m});
    adj[v].pb({u, s, m});
  }
  dfs(1);
  for(int i = 1; i < n; i++) {
    pref[i]++;
    pref[i + 1]++;
    pref[lca(i, i + 1)] -= 2;
  }
  dfs1(1);
  cout << ans;
}



