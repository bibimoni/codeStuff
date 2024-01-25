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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k; cin >> n >> k;
  vector<pair<int, int>> a(n + 1);
  vector<vector<int>> adj(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for(int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    adj[x].push_back(a[y].first);
    adj[y].push_back(a[x].first);
  }
  for(int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
  }
  vector<int> ans(n + 1);
  sort(a.begin() + 1, a.end());
  ans[a[1].second] = 0;
  a[0] = {0, 0};
  int id = 1;
  for(int i = 2; i <= n; ++i) {
    if(a[i].first != a[i - 1].first) id = i;  
    if(!adj[a[i].second].size()) {
      ans[a[i].second] = id - 1;
      continue;
    }
    int pos = -1, l = 0, r = adj[a[i].second].size() - 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(adj[a[i].second][mid] <= a[id - 1].first) {
        pos = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    ans[a[i].second] = id - 1 - (pos + 1);
  }
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

