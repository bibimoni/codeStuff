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

class dsu {
  vector<int> parent;
public:
  vector<int> cnt, size;
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    cnt.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
  }
 
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
 
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (size[a] < size[b]) swap(a, b);
    if(a != b) {
      parent[b] = a;
      size[a] += size[b];
      cnt[a] += cnt[b];
    }
    cnt[a]++;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu dsu(n + 1);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(i == dsu.find(i)) {
      int sz = dsu.size[i], co = dsu.cnt[i];
      ans += sz * (sz - 1) / 2 - co;
    }
  }
  cout << ans;
}


