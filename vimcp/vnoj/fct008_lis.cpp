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

const int N = (int) 3e5 + 5;

int n, m;
vector<int> s, t[N]; 
int a[N], c[N], b[N];
int f[N], g[N], F[N], G[N], FF[N], GG[N], RR[N];
vector<int> d[N];
bool vis[N];

int get1(int id) {
  int ans = 0;
  while(id > 0) {
    ans = max(ans, f[id]);
    id -= (id & -id);
  }
  return ans;
}
void update1(int id, int val) {
  while(id < N) {
    f[id] = max(f[id], val);
    id += (id & -id);
  }
}
int get2(int id) {
  int ans = 0;
  while(id > 0) {
    ans = max(ans, g[id]);
    id -= (id & -id);
  }
  return ans;
}
void update2(int id, int val) {
  while(id < N) {
    g[id] = max(g[id], val);
    id += (id & -id);
  }
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    s.push_back(a[i]);
  }
  for(int i = 1; i <= m; i++) {
    cin >> c[i] >> b[i];
    s.push_back(b[i]);
  }
  sort(all(s));
  s.erase(unique(all(s)), s.end());
  for(int i = 1; i <= n; i++) a[i] = lower_bound(all(s), a[i]) - s.begin() + 1;
  for(int i = 1; i <= m; i++) {
    b[i] = lower_bound(all(s), b[i]) - s.begin() + 1;
    t[b[i]].push_back(i);
  }
  memset(f, 0, sizeof(f)); memset(g, 0, sizeof(g));
  memset(F, 0, sizeof(F)); memset(G, 0, sizeof(G));
  int res = 0;
  for(int i = 1; i <= n; i++) {
    F[i] = get1(a[i] - 1) + 1;
    res = max(res, F[i]);
    update1(a[i], F[i]);
  } 
  for(int i = n; i >= 1; i--) {
    G[i] = get2(a[i] + 1) + 1;
    update2(a[i], G[i]);
  }
  for(int i = 1; i <= n; i++) {
    if(F[i] + G[i] == res + 1) {
      d[F[i]].push_back(i);
    }
  }
  memset(vis, 0, sizeof vis);
  for(int i = 1; i <= res; i++)
    if((int) d[i].size() == 1) vis[d[i][0]] = true;
  
  memset(f, 0, sizeof(f)); memset(g, 0, sizeof(g));
  memset(FF, 0, sizeof(GG)); memset(GG, 0, sizeof(GG));
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < (int) t[i].size(); j++) {
      int u = t[i][j];
      FF[i] = get1(b[u] - 1) + 1;
    }
    update1(a[i], F[i]);
  }
  for(int i = n; i >= 1; i--) {
    for(int j = 0; j < (int) t[i].size(); j++) {
      int u = t[i][j];
      GG[u] = get2(b[u] + 1) + 1;
    }
    update2(a[i], G[i]);
  }
  for(int i = 1; i <= m; i++) {
    if(FF[i] + GG[i] - 1 > res) cout << res + 1 << '\n';
    else if(FF[i] + GG[i] - 1 == res) cout << res << '\n';
    else {
      if(vis[c[i]]) cout << res - 1 << '\n';
      else cout << res << '\n';
    }
  }
}


