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
#define int int64_t 

class Dsu {
  vector<int> parent, size;

public:
  Dsu() {}
 
  Dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
  }
 
  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find(parent[v]);
  }
 
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) {
        swap(a, b);
      }
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    Dsu dsu(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> op;
    vector<int> was(n + 1, 0);
    for (int x = n - 1; x >= 1; x--) {
      vector<int> f(n, -1);
      for (int i = 1; i <= n; i++) {
        if (was[i]) {
          continue;
        }
        if (f[a[i] % x] == -1) {
          f[a[i] % x] = i;
        } else {
          was[i] = 1;
          op.push_back({i, f[a[i] % x]});
          dsu.unite(i, f[a[i] % x]);
          break;
        }
      }
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      ok &= dsu.find(1) == dsu.find(i);
    }
    if (!ok || op.size() != n - 1) {
      cout << "NO\n";
      continue;
    } 
    reverse(op.begin(), op.end());
    cout << "YES\n";
    for (const auto& [u, v] : op) {
      cout << u << ' ' << v << '\n';
    }
  }
}


