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
#define int int64_t 

const int N = int(2e3) + 5;
vector<int> adj[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("fruit.inp", "r", stdin);
  // freopen("fruit.out", "w", stdout);
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
}


