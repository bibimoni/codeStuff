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

const int N = (int) 2e5 + 5;
vector<int> adj[N];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    vector<int> deg(n + 1, 0);
    for(int j = 1; j <= k; j++) {
      int a[n + 1];
      for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i >= 3) {
          adj[a[i - 1]].push_back(a[i]);
          deg[a[i]]++;
        }
      }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
      if(!deg[i]) 
        q.push(i);
    }
    int cnt = 0;
    while(q.size()) {
      int u = q.front();
      q.pop();
      for(int v : adj[u]) {
        deg[v]--;
        if(!deg[v])
          q.push(v);
      }
      cnt++;
    }
    cout << (cnt != n ? "NO\n" : "YES\n");
  }
}


