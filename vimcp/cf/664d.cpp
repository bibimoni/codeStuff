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
const int N = (int) 1e5 + 5;
vector<pair<int, char>> adj[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v; char color;
    cin >> u >> v >> color;
    adj[u].push_back({v, color});
    adj[v].push_back({u, color}); 
  }
}

