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
#define all(_x) (_x).begin(), (_x).end()

const int N = (1ll << 22);
bool vis[N], vis1[N];
int n, m;
bool mark[N];

void dfs(int u);

void dfs1(int u) {
  if(vis1[u]) return;
  vis1[u] = true;
  for(int i = 0; i < n; i++) {
    if(u & (1ll << i)) {
      dfs1(u ^ (1ll << i));
    }
  }
  if(mark[u]) {
    dfs(u);
  }
}

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = true;
  dfs1((1 << n) - 1 - u);
}


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m;
  int a[m];
  for(int i = 0; i < m; i++) {
    cin >> a[i];
    mark[a[i]] = true;
  }
  int ans = 0;
  for(int i = 0; i < m; i++) {
    if(!vis[a[i]]) {
      dfs(a[i]);
      ans++;
    }
  }  
  cout << ans;
}


