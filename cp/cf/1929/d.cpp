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

const int N = (int) 3e5 + 5, MOD = 998244353;
vector<int> adj[N];
int dp[N];

void dfs(int u, int p = -1) {
  int mul = 1;
  for(auto v : adj[u]) {
    if(v == p)
      continue;
    dfs(v, u);
    mul *= (dp[v] + 1);
    mul %= MOD; 
  }
  dp[u] = mul;
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
      dp[i] = 0;
    }
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
}


