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
#define all(_x) (_x).begin(), (_x).end()

class dsu {
  vector<int> parent, size;
public:
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
  }
 
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
 
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
      return true;
    } else {
      return false;
    }
  }
};
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, q; cin >> n >> m >> q;
  dsu dsu(n + m + 1); 
  for(int i = 0; i < q; i++) {
    int x, y; cin >> x >> y;
    dsu.unite(x, y + n);
  }
  vector<bool> vis(n + m + 1, false);
  for(int i = 1; i <= n + m; i++) vis[dsu.find(i)] = true;
  int ans = 0; 
  for(int i = 1; i <= n + m; i++) {
    ans += vis[i];
  }
  cout << ans - 1;
}

