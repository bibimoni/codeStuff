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
const int N = (int) 2e5 + 5;
vector<int> adj[N];
int color[N], cnt[N];
bool vis[N];
int startNode = -1, maxDist = 0;
void dfs(int u, int p = -1) {
  for(int v : adj[u]) {
    if(v == p) continue;
    cnt[v] = max(cnt[v], cnt[u] + (color[u] != color[v]));
    if(cnt[v] > maxDist) {
      maxDist = cnt[v];
      startNode = v;
    }
    dfs(v, u);
  }
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> color[i];
  }
  for(int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1); 
  maxDist = 0;
  memset(cnt, 0, sizeof cnt);
  dfs(startNode);
  cout << (*max_element(cnt + 1, cnt + n + 1) + 1) / 2;
}

