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

const int N = (int) 2e5 + 5;
int a[N];

class dsu {
  vector<int> parent, size;
public:
  vector<int> val;
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
    val.resize(n);
    for(int i = 1; i <= n; i++) {
      val[i] = a[i];
    }
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
      val[a] += val[b];
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> pro(m + 1);
  for(int i = 1; i <= m; i++) {
    cin >> pro[i].first >> pro[i].second;
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    dsu dsu(n + 1);
    for(int i = l; i <= r; i++) {
      dsu.unite(pro[i].first, pro[i].second);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      ans = max(ans, dsu.val[dsu.find(i)]);
    }
    cout << ans << '\n';
  }
} 


