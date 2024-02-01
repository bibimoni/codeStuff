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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    dsu dsu(n);
    int p[n];
    for(int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
      dsu.unite(i, p[i]);
    }
    int groups = 0, ans = INF;
    for(int i = 0; i < n; i++) {
      groups += (dsu.find(i) == i);
    }
    for(int i = 0; i < n - 1; i++) {
      if(dsu.find(p[i]) != dsu.find(p[i + 1])) {
        ans = min(ans, n - groups + 1);
      }
      else {
        ans = min(ans, n - groups - 1);
      }
    }
    cout << ans << '\n';
  }  
}


