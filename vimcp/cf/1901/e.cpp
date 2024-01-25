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
#define all(x)         x.begin(), x.end()
const int INF = (int) 2e9, N = (int) 5e5 + 5;
vector<int> adj[N];
int dp[N], a[N], ans = 0;

void dfs(int u, int p = -1) {
  int takeSubTree[4];
  for(int cnt = 1; cnt < 4; cnt++) takeSubTree[cnt] = -INF;
  takeSubTree[0] = 0;
  for(auto v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
    //update the max value can we get if we take some subtrees
    for(int cnt = 3; cnt >= 0; cnt--) {
      takeSubTree[min(cnt + 1, 3ll)] 
        = max(takeSubTree[min(cnt + 1, 3ll)], takeSubTree[cnt] + dp[v]); 
    }
  }
  dp[u] = a[u];
  ans = max(ans, dp[u]); //take the vertex and stop
  ans = max(ans, a[u] + takeSubTree[1]); //take 1 subtree and the vertex -> stop
  dp[u] = max(dp[u], takeSubTree[1]); //take 1 subtree but don't take the vertex -> keep going
  ans = max(ans, takeSubTree[2]); //take 2 subtrees but don't take the vertex -> stop
  dp[u] = max(dp[u], a[u] + takeSubTree[2]); //take 2 subtrees and the vertex -> keep going
  ans = max(ans, takeSubTree[3] + a[u]); //take 3 subtrees and always take the vertex
  dp[u] = max(dp[u], takeSubTree[3] + a[u]);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      adj[i].clear();
      dp[i] = 0;
    }
    ans = 0;
    for(int u, v, i = 0; i < n - 1; ++i) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1);
    cout << ans << '\n';
  }
}


