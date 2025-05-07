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

const int N = (int) 1e4 + 5, INF = (int) 2e9;

void bin(int num) {
  string s;
  while(num) {
    s += (num % 2) + '0';
    num >>= 1;
  }
  reverse(all(s));
  dbg(s);
}
vector<int> adj[N]; ;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n, m; cin >> n >> m;
    for(int i = 0, u, v; i < m; i++) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int f; cin >> f;
    int h[f + 1];
    for(int i = 1; i <= f; i++) cin >> h[i];
    int k; cin >> k;
    int p[k + 1], idx[f + 1]; vector<int> mask(n + 1, 0);
    for(int i = 1; i <= k; i++) {
      cin >> p[i];
      idx[p[i]] = i;
      mask[h[p[i]]] |= 1 << i;
    }
    queue<int> q;
    q.push(1);
    vector<int> d(n, INF);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(int v : adj[u]) {
        if(d[v] == INF) {
          d[v] = d[u] + 1;
          q.push(v);
          mask[v] |= mask[u];
        }
        else if(d[v] == d[u] + 1) {
          mask[v] |= mask[u];
        }
      }
    }
    /*
    for(int i = 1; i <= f; i++) {
      bin(mask[h[i]]);
      dbg(h[i]);
    }
    */
    vector<int> valid(1 << (k + 1), -1);
    for(int i = 1; i < (1 << (k + 1)); i++) {
      vector<int> t;
      for(int j = 1; j <= k; j++) {
        if((i >> j) & 1) t.push_back(p[j]);
      }
      sort(all(t), [&] (int x, int y) {
        return d[h[x]] < d[h[y]];
      });
      bool check = true;
      for(int j = 1; j < t.size(); j++) {
        int id = idx[v[j - 1]], y = v[j];
        if(!((mask[h[y]] >> id) & 1)) check = false;
      }
      if(check) valid[i] = t.back();
    }
  }  
}


