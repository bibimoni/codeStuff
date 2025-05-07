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
struct Edge {
  int u, v, l, r;
};

const int N = (int) 1e3 + 5, INF = (int) 1e18;
int n, m;

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
  cin >> n >> m;
  vector<int> leftbound;
  vector<Edge> edges;
  for(int i = 0; i < m; i++) {
    int u, v, l, r; cin >> u >> v >> l >> r;
    edges.push_back({u, v, l, r});
    leftbound.push_back(l);
  }
  int ans = -1;
  sort(leftbound.begin(), leftbound.end());
  for(int left : leftbound) {
    int l = left, r = 1e6;
    while(l <= r) {
      int right = (l + r) >> 1;
      dsu dsu(n + 1);
      for(auto [u, v, le, re] : edges) {
        if(le <= left && right <= re) dsu.unite(u, v);
      }
      if(dsu.find(1) == dsu.find(n)) {
        ans = max(right - left + 1, ans);
        l = right + 1;
      }
      else {
        r = right - 1;
      }
    }
  }
  if(ans > 0) cout << ans;
  else cout << "Nice work, Dima!";
}

