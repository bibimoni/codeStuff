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

const int N = (int) 2e5 + 5;
vector<int> adj[N];
int a[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, q; cin >> n >> m >> q;
  for(int u, v, i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);    
  }
  for(int i = 1; i <= m; i++) cin >> a[i];
  while(q--) {

  }
}

