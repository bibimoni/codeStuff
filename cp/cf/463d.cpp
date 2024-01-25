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

const int N = (int) 1e4 + 5;
vector<int> adj[N];
int idx[N][5], dp[N];
bool vis[N] = {false};
void dfs(int u, int p = -1) {
  if(vis[u]) return;
  dp[u]++;
  vis[u] = true;  
  for(int v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
    dp[u] = max(dp[u], dp[v] + 1);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k; cin >> n >> k;
  if(n == 1) {
    cout << "1\n"; return 0;
  }
  int x;
  for(int j = 0; j < k; j++) {
    for(int i = 0; i < n; i++) {
      cin >> x;
      idx[x][j] = i;
    }
  }
  vector<int> nodes;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      bool check = true;
      for(int p = 0; p < k; p++) {
        if(idx[i][p] >= idx[j][p]) {
          check = false;
          break;
        }
      }
      if(check) {
        adj[i].push_back(j);
        nodes.push_back(i);
      }
    }
  }
  for(int node : nodes) {
    if(vis[node]) continue;
    dfs(node);
  }
  cout << *max_element(dp, dp + N);
}

