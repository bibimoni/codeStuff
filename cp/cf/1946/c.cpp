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
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    function<int(int, int, int)> dfs = [&] (int u, int p, int x) -> int {
      int cnt = 1;
      for(int v : adj[u]) {
        if(v == p)
          continue;
        cnt += dfs(v, u, x);
      }
      if(cnt >= x)
        cnt = 0;
      return cnt;
    };
    int l = 1, r = n, ans = 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      int cut = dfs(1, -1, mid);
      
      if(cut >= mid) {
        l = mid + 1;
        ans = mid;
      }
      else {
        r = mid - 1;
      }
    }
    cout << ans << '\n';
  }
}


