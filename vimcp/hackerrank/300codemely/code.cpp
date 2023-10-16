/**
 * File              : code.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 05.10.2023
 * Last Modified By  : distiled
 */
#include <algorithm>
#include<bits/stdc++.h>
#include <queue>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define makeUnique(x)  sort(all(x)); x.erase(unique(all(x)), x.end());
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
const int 
      MAXN = (int) 1e6 + 5, 
      INF = (int) 1e18, 
      MOD = (int) 1e9 + 7; //998244353
inline int nxt() { int n; cin >> n; return n; }

vector<pair<int, int>> adj[MAXN];
int n, m;
vector<vector<int>> d(501, vector<int>(501, INF));
int dickcha(int a, int b) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  d[a][a] = 0;
  q.push({0, a});
  while(!q.empty()) {
   auto [currW, u] = q.top(); q.pop();
    if(currW > d[a][u]) continue;
   for(auto [v, w] : adj[u]) {
       if(d[a][v] > d[a][u] + w) {
         d[a][v] = d[a][u] + w;
         q.push({d[a][v], v});
       }
     }
   }
   if(d[a][b] == INF) return -1;
   return d[a][b];
}

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int q;
  cin >> n >> m >> q;
  for(int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }
  while(q--) {
    int a, b; cin >> a >> b;
    if(d[a][a] == INF && d[b][b] == INF) {
      cout << dickcha(a, b) << endl;
    }
    else {
      cout << min(d[a][b], d[b][a]) << endl;
    }
    dbg(dickcha(a, b));
  }
}

