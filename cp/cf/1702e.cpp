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
  vector<int> cycle;
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    cycle.assign(n, 0);
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
      cycle[a] += cycle[b];
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; 
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    bool ok = true;
    dsu dsu(n + 1);
    vector<int> cnt(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
      cnt[a[i].first]++;
      cnt[a[i].second]++;
      dsu.unite(a[i].first, a[i].second);
      dsu.cycle[dsu.find(a[i].first)]++;
    }
    if(!ok) {
      cout << "NO\n";
      continue;
    }
    for(int i = 1; i <= n; i++) {
      if(cnt[i] != 2) {
        ok = false;
        break;
      }
    }
    for(int i = 1; i <= n; i++) {
      if(dsu.cycle[dsu.find(i)] % 2 != 0) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}

